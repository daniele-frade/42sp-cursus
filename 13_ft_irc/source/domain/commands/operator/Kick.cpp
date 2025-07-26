#include "commands/operator/Kick.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "ClientService.hpp"
#include "ChannelService.hpp"
#include "Macros.hpp"
#include "Server.hpp"


Kick::Kick(Server* server) : ACommand(server, true) {}
Kick::~Kick() {}


// syntax: KICK #<channel> <client> :<message>
void Kick::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    std::string channel_name = args[0];
    std::string target = args[1];
    std::string reason = _extract_reason(args);

    Channel* channel = _server->get_channel(channel_name);
    if (!_is_valid_channel(client, channel, channel_name))
        return;

    Client* target_client = _server->get_client(target);
    if (!_is_valid_client(client, target_client, target) || !_is_on_channel(target_client, channel))
        return;

    if (!_has_channel_privileges(client, channel))
        return;

    if(_kicking_self(client, channel, target_client))
        return;

    if (_kicking_admin(client, channel, target_client))
        return;

    std::cout << "KICK::Kicking client..." << std::endl;
    ChannelService::kick_client(channel, client, target_client, reason);
    ClientService::kicked_from_channel(client, target_client, channel, reason);
    std::cout << "SUCCEDED KICK" << std::endl;
}

bool Kick::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "KICK::Validate parameters..." << std::endl;
    if (args.size() > 1)
        return true;
    ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("KICK")));
    return false;
}

std::string Kick::_extract_reason(const std::vector<std::string>& args) {
    std::cout << "KICK::Extracting reason..." << std::endl;
    if (!(args.size() >= 3 && (args[2][0] != ':' || args[2].size() > 1)))
        return "";

    std::string reason = "";
    for (size_t i = 2; i < args.size(); ++i) {
        reason.append(args[i]);
        if (i != args.size() - 1)
            reason.append(" ");
    }
    return reason;
}

bool    Kick::_kicking_self(Client* client, Channel* channel, Client* target_client) {
    if (client != target_client)
        return false;

    ClientService::send_message(client, ERR_CANNOTSENDTOSELF(client->get_nickname(), channel->get_name()));
    return true;

}

bool    Kick::_kicking_admin(Client* client, Channel* channel, Client* target_client) {
    if (channel->get_admin() != target_client)
        return false;

    ClientService::send_message(client, ERR_NOPRIVILEGES(client->get_nickname(), channel->get_name()));
    return true;

}