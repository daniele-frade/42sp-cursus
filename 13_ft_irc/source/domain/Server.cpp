#include "Server.hpp"
#include "interfaces/IVault.hpp"
#include "interfaces/ISocket.hpp"
#include "SignalManager.hpp"
#include "ServerException.hpp"
#include "Channel.hpp"
#include "CommandHandler.hpp"
#include "Client.hpp"
#include "Constants.hpp"
#include "Multiplexer.hpp"
#include "Macros.hpp"
#include "Utils.hpp"


Server::Server(IVault* vault, ISocket* socket, IMultiplexer* multiplexer) :
      _running(false),
      _vault(vault), 
      _socket(socket), 
      _multiplexer(multiplexer),
      _datetime(Utils::get_time()) {}

Server::~Server() {
    std::set<Channel*>::iterator channel_it;
    for (channel_it = _channels.begin(); channel_it != _channels.end(); ++channel_it) {
        Channel* channel = *channel_it;
        delete channel;
    }
    _channels.clear();

    delete _vault;
    delete _socket;
    delete _multiplexer;
}

IMultiplexer*                   Server::get_multiplexer() const { return _multiplexer; }
CommandHandler*                 Server::get_command_handler() const { return _command_handler; }
const std::set<Channel*>&       Server::get_channels() const { return _channels; }
const std::map<int, Client*>&   Server::get_clients() const { return _multiplexer->get_clients(); }
const std::string&              Server::get_datetime() const { return _datetime; }

Channel*                        Server::get_channel(const std::string& name) {
    for (std::set<Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it) {
        if ((*it)->get_name() == name)
            return *it;
    }
    return NULL; 
}


Client* Server::get_client(const std::string& target) {
    return _multiplexer->get_client(target);
}

void Server::set_command_handler(CommandHandler* handler) { _command_handler = handler; }

void Server::start() {
    try {
        _running = true;
        SignalManager::initialize(&_running);

        CommandHandler handler = CommandHandler(this);
        set_command_handler(&handler);

        int total_events;

        std::string source = "ft_irc ";

        std::cout << RPL_CREATED(source, _datetime) << std::endl;

        _multiplexer->subscribe_fd_for_monitoring(_socket->get_fd());

        while(_running) {
            total_events = _multiplexer->check_for_events();
            _multiplexer->handle_events(total_events, &handler);
        }
    } catch (const std::exception& e) {
        throw ServerException(e, "Unable to turn on the server.");
    }
}

void Server::stop() {
    try {
        if (_running) {
            _running = false;
            _multiplexer->unsubscribe_fd_for_monitoring(_socket->get_fd());
        }

        std::cout << "Server has been shut down." << std::endl;
    } catch (const std::exception& e) {
        throw ServerException(e, "Unable to turn off the server.");
    }
}

Channel* Server::create_channel(std::string name, Client* client) {
    Channel* channel = new Channel(client, name);
    _channels.insert(channel);

    return channel;
}

bool Server::is_valid_pass(std::string pass) {
    return _vault->validate_password(pass);
}
