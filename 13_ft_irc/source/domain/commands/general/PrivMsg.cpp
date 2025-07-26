#include "commands/general/PrivMsg.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "ClientService.hpp"
#include "ChannelService.hpp"
#include "Macros.hpp"
#include "Server.hpp"


PrivMsg::PrivMsg(Server* server) : ACommand(server, true) {}
PrivMsg::~PrivMsg() {}


// syntax: PRIVMSG <nickname> :<message>
//         PRIVMSG #<channel> :<message>
void PrivMsg::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    std::string target = args[0];
    std::string message = _build_message(args);

    std::cout << "PRIVMSG::Sending message..." << std::endl;
    if (target.at(0) == '#')
        _handle_channel_message(client, target, message);
    else
        _handle_client_message(client, target, message);
    std::cout << "SUCCEDED PRIVMSG" << std::endl;
}


void PrivMsg::_handle_channel_message(Client* client, std::string& channel_name, const std::string& message) {
    std::cout << "PRIVMSG::Handling channel message..." << std::endl;

    Channel* channel = _server->get_channel(channel_name);
    if (!_is_valid_channel(client, channel, channel_name))
        return;

    if (!_is_on_channel(client, channel))
        return;

    ChannelService::broadcast(channel, RPL_PRIVMSG(client->get_info(), channel_name, message), client);
    std::cout << "PRIVMSG::Message sent to channel." << std::endl;
}


void PrivMsg::_handle_client_message(Client* client, const std::string& target, const std::string& message) {
    std::cout << "PRIVMSG::Handling client message..." << std::endl;

    Client* target_client = _server->get_client(target);
    if (!_is_valid_client(client, target_client, target))
        return;

    ClientService::send_message(target_client, RPL_PRIVMSG(client->get_info(), target, message));
    std::cout << "PRIVMSG::Message sent to client..." << std::endl;
}

bool PrivMsg::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "PRIVMSG::Validate parameters..." << std::endl;
    if (args.size() < 2 || args[0].empty() || args[1].empty()) {
        ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("PRIVMSG")));
        return false;
    }
    return true;
}

std::string PrivMsg::_build_message(const std::vector<std::string>& args) {
    std::cout << "PRIVMSG::Building message..." << std::endl;
    std::string message;
    for (std::vector<std::string>::const_iterator it = args.begin() + 1; it != args.end(); ++it)
        message.append(*it + " ");

    if (message.at(0) == ':')
        message = message.substr(1);

    return message;
}
