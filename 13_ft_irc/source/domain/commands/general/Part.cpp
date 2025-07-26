#include "commands/general/Part.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "ClientService.hpp"
#include "ChannelService.hpp"
#include "Macros.hpp"
#include "Server.hpp"


Part::Part(Server* server) : ACommand(server, true) {}
Part::~Part() {}


// syntax: PART #<channel> :<message>
void    Part::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    std::string channel_name = args[0];
    Channel     *channel = _server->get_channel(channel_name);

    if (!_is_valid_channel(client, channel, channel_name))
        return;

    if (!_is_client_in_channel(client, channel, channel_name))
        return;

    std::cout << "PART::Remove client..." << std::endl;
    ChannelService::remove_client(channel, client);
    ClientService::leave_channel(client, channel);
    std::cout << "SUCCEDED PART" << std::endl;
}

bool Part::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "PART::Validate parameters..." << std::endl;
    if (args.size() > 0)
        return true;
    ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("PART")));
    return false;
}

bool Part::_is_client_in_channel(Client* client, Channel* channel, const std::string& name) {
    std::cout << "PART::Validate if client is in channel..." << std::endl;
    if (channel && client->get_channel() && client->get_channel()->get_name() == name)
        return true;

    ClientService::send_message(client, ERR_NOSUCHCHANNEL(client->get_nickname(), name));
    return false;
}
