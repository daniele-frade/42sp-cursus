#include "commands/general/Join.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "ClientService.hpp"
#include "ChannelService.hpp"
#include "CommandHandler.hpp"
#include "Macros.hpp"
#include "Server.hpp"

Join::Join(Server* server) : ACommand(server, true) {}
Join::~Join() {}


// syntax: JOIN #<channel> <key>
void Join::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    if (_is_already_in_channel(client))
        return;

    std::string pass = args.size() == 2 ? args[1] : "";
    std::string channel_name = args[0];

    Channel* channel = _server->get_channel(channel_name);
    if (channel != NULL) {
        _join_channel(channel_name, client, pass);
        return;
    }

    _create_channel(channel_name, client);
}

void Join::_create_channel(std::string& channel_name, Client* client) {
    Channel* channel = _server->create_channel(channel_name, client);

    std::cout << "JOIN::Add client..." << std::endl;
    if (ChannelService::add_client(channel, client)) {
        ClientService::join_channel(client, channel);
        _send_client_list(channel, client);
    }

    std::set<Client*> clients = channel->get_clients();
    std::cout << "Clients in the channel: ";
    for (std::set<Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
        std::cout << (*it)->get_nickname() << " ";
    }
    std::cout << std::endl;
    
    std::cout << "SUCCEDED JOIN" << std::endl;
}

void Join::_join_channel(std::string& channel_name, Client* client, std::string pass) {
    Channel* channel = _server->get_channel(channel_name);
    if (!_is_valid_channel(client, channel, channel_name))
        return;

    if (_is_channel_full(channel, client, channel_name))
        return;

    if (!_is_channel_key_valid(channel, client, pass, channel_name))
        return;

    if (!_is_guest(channel, client, channel_name))
        return;

    if (channel->get_admin() == NULL)
        channel->set_admin(client);

    std::cout << "JOIN::Add client..." << std::endl;
    if (ChannelService::add_client(channel, client)) {
        ClientService::join_channel(client, channel);
        _send_client_list(channel, client);
    }

    std::set<Client*> clients = channel->get_clients();
    std::cout << "Clients in the channel: ";
    for (std::set<Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
        std::cout << (*it)->get_nickname() << " ";
    }
    std::cout << std::endl;
    std::cout << "SUCCEDED JOIN" << std::endl;
}

bool Join::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "JOIN::Validate parameters..." << std::endl;
    if ((args.size() == 1 || args.size() == 2) && args[0].at(0) == '#')
        return true;
    ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("JOIN")));
    return false;
}

bool Join::_is_already_in_channel(Client* client) {
    std::cout << "JOIN::Validate if is already in channel..." << std::endl;
    if (client->get_channel() == NULL)
        return false;
    ClientService::send_message(client, ERR_TOOMANYCHANNELS(client->get_nickname(), client->get_channel()->get_name()));
    return true;
}

bool Join::_is_channel_full(Channel* channel, Client* client, const std::string& name) {
    std::cout << "JOIN::Validate if channel is full..." << std::endl;
    if (channel->get_limit().first && ChannelService::get_total_clients(channel) >= channel->get_limit().second) {
        ClientService::send_message(client, ERR_CHANNELISFULL(client->get_nickname(), name));
        return true;
    }
    return false;
}

bool Join::_is_channel_key_valid(Channel* channel, Client* client, const std::string& pass, std::string name) {
    std::cout << "JOIN::Validate if key correct..." << std::endl;
    if (!channel->get_key().first || (channel->get_key().first && channel->get_key().second == pass))
        return true;
    ClientService::send_message(client, ERR_BADCHANNELKEY(client->get_nickname(), name));
    return false;
}

bool Join::_is_guest(Channel* channel, Client* client, const std::string& name) {
    std::cout << "JOIN::Validate if client is guest..." << std::endl;
    if (!channel->get_guests().first || (channel->get_guests().first && channel->get_guest(client)))
        return true;
    ClientService::send_message(client, ERR_INVITEONLYCHAN(client->get_nickname(), name));
    return false;
}

void Join::_send_client_list(Channel* channel, Client* client) {
    std::set<Client*> clients = channel->get_clients();
    std::string user_info;
    for (std::set<Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
        user_info += (*it)->get_nickname() + " ";
    }

    CommandHandler* handler = _server->get_command_handler();
    handler->handle_command(client, "TOPIC " + channel->get_name());
    handler->handle_command(client, "WHO " + channel->get_name());
    handler->handle_command(client, "NAMES " + channel->get_name());
}
