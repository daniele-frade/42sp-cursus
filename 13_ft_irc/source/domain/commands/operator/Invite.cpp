#include "commands/operator/Invite.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "ClientService.hpp"
#include "ChannelService.hpp"
#include "Macros.hpp"
#include "Server.hpp"


Invite::Invite(Server* server) : ACommand(server, true) {}
Invite::~Invite() {}


// syntax: INVITE <nickname> #<channel>
void Invite::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    std::string target = args[0];
    std::string channel_name = args[1];

    Channel* channel = _server->get_channel(channel_name);
    if (!_is_valid_channel(client, channel, channel_name))
        return;

    Client* dest = _server->get_client(target);
    if (!_is_valid_client(client, dest, target))
        return;

    if (!_is_on_channel(client, channel) || _is_already_on_channel(client, dest, channel))
        return;

    if (channel->get_guests().first && !_has_channel_privileges(client, channel))
        return;

    if (channel->get_guests().first)
        channel->add_to_guests(dest);

    std::cout << "INVITE::Sending invite..." << std::endl;
    channel->add_to_guests(dest);
    ClientService::send_message(client, RPL_INVITING(client->get_nickname(), target, channel_name));
    ClientService::send_message(dest, RPL_INVITE(dest->get_nickname(), channel_name, client->get_nickname()));
    std::cout << "SUCCEDED INVITE" << std::endl;
}

bool Invite::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "INVITE::Validate parameters..." << std::endl;
    if (args.size() == 2)
        return true;
    ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("INVITE")));
    return false;
}
