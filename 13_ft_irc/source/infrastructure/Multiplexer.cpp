#include "Multiplexer.hpp"
#include "Channel.hpp"
#include "ChannelService.hpp"
#include "Client.hpp"
#include "CommandHandler.hpp"
#include "Utils.hpp"


Multiplexer::Multiplexer(int server_fd) {
    _server_fd = server_fd;
    _epoll_fd = epoll_create1(0);
    if (_epoll_fd == -1)
        throw std::runtime_error("Failed to create epoll file descriptor");
}

Multiplexer::~Multiplexer() {
    if (_epoll_fd != -1)
        ::close(_epoll_fd);

    std::map<int, Client*>::iterator client_it;
    for (client_it = _clients.begin(); client_it != _clients.end(); ++client_it) {
        Client* client = client_it->second;
        ::close(client->get_fd());
        delete client;
    }
    _clients.clear();
}

int                         Multiplexer::get_epoll_fd() const { return _epoll_fd; }

std::map<int, Client*>&     Multiplexer::get_clients() { return _clients; }

Client*                     Multiplexer::get_client(std::string target) {
    std::map<int, Client*>::iterator it;

    for (it = _clients.begin(); it != _clients.end(); ++it) {
        Client* client = it->second;
        if (client->get_nickname() == target)
            return client;
    }

    return NULL;
}

void Multiplexer::subscribe_fd_for_monitoring(int fd) {
    epoll_event event;

    bzero(&event, sizeof(epoll_event));
    event.events = EPOLLIN | EPOLLOUT | EPOLLERR | EPOLLHUP;
    event.data.fd = fd;
    if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, fd, &event) == -1)
        throw std::runtime_error("Failed to add fd to epoll");
}


void Multiplexer::unsubscribe_fd_for_monitoring(int fd) {
    if (epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, fd, NULL) < 0)
        throw std::runtime_error("Error while removing client fd from epoll");
}

int Multiplexer::check_for_events() {

    int total_events = epoll_wait(_epoll_fd, _events, MAX_EVENTS, -1);
    if (total_events == -1) {
        if (errno == EINTR) {
            return 0;
        }
        throw std::runtime_error("Error while polling with epoll");
    }

    return total_events;
}

void Multiplexer::handle_events(int total_events, CommandHandler* handler) {
    for (int i = 0; i < total_events; i++) {

        if (_events[i].data.fd == _server_fd) {
            if (_events[i].events & EPOLLIN)
                connect_client(_events[i].data.fd);
        } else {
            if ((_events[i].events & (EPOLLHUP | EPOLLERR)))
                disconnect_client(_events[i].data.fd);

            if (_events[i].events & EPOLLIN)
                handle_client(_events[i].data.fd, handler);

        }
    }
}

void Multiplexer::disconnect_client(int client_fd) {
    unsubscribe_fd_for_monitoring(client_fd);

    std::map<int, Client*>::iterator it = _clients.find(client_fd);
    if (it != _clients.end()) {
        Client*     client = it->second;
        Channel*    channel = client->get_channel();
        if (channel) {
            ChannelService::remove_client(channel, client);
        }
        _clients.erase(it);
        delete client;
    }

    ::close(client_fd);

    std::string datetime = Utils::get_time();
    std::cout << "[" << datetime << "] Client disconnected." << std::endl;
}


int Multiplexer::connect_client(int server_fd) {
    sockaddr_in addr = {};
    socklen_t   size = sizeof(addr);

    int client_fd = _accept_connection(server_fd, &addr, &size);
    Client* client = _create_client(client_fd, addr);

    _clients.insert(std::make_pair(client_fd, client));
    subscribe_fd_for_monitoring(client_fd);

    std::string datetime = Utils::get_time();
    std::cout << "[" << datetime << "] Client connected." << std::endl;
    return client_fd;
}


void Multiplexer::handle_client(int client_fd, CommandHandler* handler) {
    try {
        Client* client = _clients.at(client_fd);
        char buffer[BUFFER_SIZE];
        bzero(buffer, BUFFER_SIZE);

        ssize_t bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == 0) {
            disconnect_client(client_fd);
            return;
        } else if (bytes_received < 0) {
            return;
        }

        _client_buffers[client_fd].append(buffer, bytes_received);

        std::string& total_buffer = _client_buffers[client_fd];
        size_t pos;
        while ((pos = total_buffer.find('\n')) != std::string::npos) {
            std::string message = total_buffer.substr(0, pos + 1);
            total_buffer.erase(0, pos + 1);
            handler->handle_command(client, message);
        }

    } catch (const std::exception& e) {
        std::cout << "Error while handling the client message! " << e.what() << std::endl;
    }
}

std::string Multiplexer::read_client_message(int client_fd) {
    std::string message;
    char buffer[BUFFER_SIZE];

    try {
        while (true) {
            bzero(buffer, BUFFER_SIZE);

            ssize_t bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
            if (bytes_received == 0) {
                disconnect_client(client_fd);
                return "";
            } else if (bytes_received < 0) {
                return "";
            }
            message.append(buffer, bytes_received);

            if (message.find('\n') != std::string::npos)
                break;
        }

        return message;

    } catch (const std::exception& e) {
        std::cout << "Error processing the message: " << e.what() << std::endl;
        return message;
    }
}


void Multiplexer::send_client_message(int client_fd, const std::string& message) {
    std::string buffer = message + "\r\n";
    if (send(client_fd, buffer.c_str(), buffer.length(), 0) == -1)
        throw std::runtime_error("Error while sending a message to a client!");
}


void Multiplexer::handle_read_event(int fd) {
    if (fd != _server_fd)
        read_client_message(fd);
    else
        connect_client(fd);
}

void Multiplexer::handle_error_event(int fd) {
    if (fd != _server_fd)
        disconnect_client(fd);
}

void Multiplexer::handle_hangup_event(int fd) {

    if (fd != _server_fd)
        disconnect_client(fd);
}

void Multiplexer::handle_write_event(int fd) {
    (void)fd;
    return ;
}

int Multiplexer::_accept_connection(int server_fd, sockaddr_in* addr, socklen_t* size) {
    int client_fd = ::accept(server_fd, (sockaddr*)addr, size);
    if (client_fd == -1)
        throw std::runtime_error("Error to accept connection");
    return client_fd;
}

std::string Multiplexer::_get_client_hostname(const struct in_addr& client_ip) {
    struct hostent* host = gethostbyname(inet_ntoa(client_ip));
    
    if (host && host->h_name) {
        return std::string(host->h_name);
    }
    return std::string(inet_ntoa(client_ip));
}


Client* Multiplexer::_create_client(int client_fd, const sockaddr_in& addr) {
    std::string client_host = _get_client_hostname(addr.sin_addr);
    int client_port = ntohs(addr.sin_port);
    return new Client(client_fd, client_host, client_port);
}