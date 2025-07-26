#include "Socket.hpp"
#include "Constants.hpp"


Socket::Socket(const std::string& host, int port) : _max_connections(MAX_CONNECTIONS) {
    _create_socket();
    _configure_socket();
    _set_non_blocking();
    _configure_address(host, port);
    _bind_socket_to_address();
    _set_listening();
}

Socket::~Socket() {
    if (_socket_fd != -1)
        ::close(_socket_fd);
}

int Socket::get_fd() const { return _socket_fd; }


void Socket::_create_socket() {
    _socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket_fd == -1)
        throw std::runtime_error("Error while creating a socket");
}

void Socket::_configure_socket() {
    int optval = 1;
    if (setsockopt(_socket_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1)
        throw std::runtime_error("Error while setting socket options");
}

void Socket::_set_non_blocking() {
    if (fcntl(_socket_fd, F_SETFL, O_NONBLOCK) == -1)
        throw std::runtime_error("Error while setting socket to NON-BLOCKING");
}

void Socket::_configure_address(const std::string& host, int port) {
    memset(&_address, 0, sizeof(_address));
    _address.sin_family = AF_INET;
    _address.sin_port = htons(port);

    _address.sin_addr.s_addr = inet_addr(host.c_str());
    if (_address.sin_addr.s_addr == INADDR_NONE)
        throw std::runtime_error("Error while converting or invalid address");
}

void Socket::_bind_socket_to_address() {
    if (::bind(_socket_fd, (sockaddr*)&_address, sizeof(_address)) == -1)
        throw std::runtime_error("Error while binding a socket");
}

void Socket::_set_listening() {
    if (::listen(Socket::_socket_fd, _max_connections) == -1)
        throw std::runtime_error("Error while listening on a socket");
}
