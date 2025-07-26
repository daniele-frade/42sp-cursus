#include "commands/misc/Notice.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "ClientService.hpp"
#include "ChannelService.hpp"
#include "Macros.hpp"
#include "Server.hpp"


Notice::Notice(Server* server) : ACommand(server, true) {}
Notice::~Notice() {}


// syntax: NOTICE <nickname> :<message>
//         NOTICE #<channel> :<message>
void Notice::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    std::string target = args[0];
    std::string message = _build_message(args);

    std::cout << "NOTICE::Sending message..." << std::endl;
    if (target.at(0) == '#')
        _handle_channel_message(client, target, message);
    else
        _handle_client_message(client, target, message);
    std::cout << "SUCCEDED NOTICE" << std::endl;
}


void Notice::_handle_channel_message(Client* client, std::string& channel_name, const std::string& message) {
    std::cout << "NOTICE::Handling channel message..." << std::endl;

    Channel* channel = _server->get_channel(channel_name);
    Channel* client_channel = client->get_channel();
    if (!channel || client_channel != channel)
        return;

    ChannelService::broadcast(client_channel, RPL_NOTICE(client->get_info(), channel_name, message), client);
    std::cout << "NOTICE::Message sent to channel." << std::endl;
}


void Notice::_handle_client_message(Client* client, const std::string& target, const std::string& message) {
    std::cout << "NOTICE::Handling client message..." << std::endl;

    Channel* channel = client->get_channel();
    Client* dest = _server->get_client(target);
    if (!dest || !channel || channel->get_name() != target)
        return;

    ClientService::send_message(dest, RPL_NOTICE(client->get_info(), target, message));
    std::cout << "NOTICE::Message sent to client..." << std::endl;
}


bool Notice::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "NOTICE::Validate parameters..." << std::endl;
    (void)client;
    if (args.size() < 2)
        return false;
    return true;
}

std::string Notice::_build_message(const std::vector<std::string>& args) {
    std::cout << "NOTICE::Building message..." << std::endl;
    std::string message;
    for (std::vector<std::string>::const_iterator it = args.begin() + 1; it != args.end(); ++it)
        message.append(*it + " ");

    if (message.at(0) == ':')
        message = message.substr(1);

    return message;
}
