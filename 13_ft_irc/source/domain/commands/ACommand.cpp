#include "commands/ACommand.hpp"
#include "Channel.hpp"
#include "ChannelService.hpp"
#include "Client.hpp"
#include "ClientService.hpp"
#include "Macros.hpp"
#include "Utils.hpp"
#include "Server.hpp"


ACommand::ACommand(Server* server, bool auth) : _auth(auth), _server(server) {}

ACommand::~ACommand() {}


bool    ACommand::auth_required() const { return _auth; }

bool ACommand::_is_on_channel(Client* client, Channel* channel) {
    std::cout << "ACOMMAND::Validate if client is on channel..." << std::endl;
    if (channel == client->get_channel())
        return true;
    ClientService::send_message(client, ERR_NOTONCHANNEL(client->get_nickname(), channel->get_name()));
    return false;
}

bool ACommand::_is_valid_channel(Client* client, Channel* channel, std::string target) {
    std::cout << "ACOMMAND::Validate if a channel exists..." << std::endl;
    if (channel && channel->get_name() == target)
        return true;
    ClientService::send_message(client, ERR_NOSUCHCHANNEL(client->get_nickname(), target));
    return false;
}

bool ACommand::_has_channel_privileges(Client* client, Channel* channel) {
    std::cout << "ACOMMAND::Validate if client has privileges..." << std::endl;
    Client* admin = channel->get_admin();
    if (client == admin || (channel->get_operators().first && channel->get_operator(client)))
        return true;
    ClientService::send_message(client, ERR_CHANOPRIVSNEEDED(client->get_nickname(), channel->get_name()));
    return false;
}

bool ACommand::_is_already_registered(Client* client) {
    std::cout << "ACOMMAND::Validate if client is already registered..." << std::endl;
    if (client->get_state() != REGISTERED)
        return false;
    ClientService::send_message(client, ERR_ALREADYREGISTERED(client->get_nickname()));
    return true;
}

bool ACommand::_is_valid_client(Client* client, Client* dest, const std::string& dest_nickname) {
    std::cout << "ACOMMAND::Validate if client exists..." << std::endl;
    if (dest)
        return true;
    ClientService::send_message(client, ERR_NOSUCHNICK(client->get_nickname(), dest_nickname));
    return false;
}

bool ACommand::_is_client_on_channel(Client* client, Channel* channel) {
    std::cout << "ACOMMAND::Validate if client is on channel..." << std::endl;
    if (client->get_channel() && client->get_channel() == channel)
        return true;
    ClientService::send_message(client, ERR_USERNOTINCHANNEL(client->get_nickname(), client->get_nickname(), channel->get_name()));
    return false;
}

bool ACommand::_is_already_on_channel(Client* client, Client* dest, Channel* channel) {
    std::cout << "ACOMMAND::Validate if client is already on channel..." << std::endl;
    if (dest->get_channel() != channel)
        return false;
    ClientService::send_message(client, ERR_USERONCHANNEL(client->get_nickname(), dest->get_nickname(), channel->get_name()));
    return true;
}

void ACommand::_set_registered(Client* client) {
    client->set_state(REGISTERED);
    std::string server = "ft_irc";
    std::string nickname = client->get_nickname();
    ClientService::send_message(client, RPL_WELCOME(nickname, client->get_info()));
    ClientService::send_message(client, RPL_YOURHOST(nickname, server));
    ClientService::send_message(client, RPL_CREATED(nickname, _server->get_datetime()));
    ClientService::send_message(client, RPL_MYINFO(nickname, client->get_nickname()));
    ClientService::send_message(client, RPL_ISUPPORT(nickname));
}

std::string ACommand::_get_prefix(Client* client, Channel* channel) {
    if (channel->get_admin() == client)
        return "~";
    if (channel->get_operators().first)
        return channel->get_operator(client) ? "@" : "";
    return "";
}
