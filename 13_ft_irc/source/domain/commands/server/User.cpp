#include "commands/server/User.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "ClientService.hpp"
#include "ChannelService.hpp"
#include "Macros.hpp"
#include "Server.hpp"


User::User(Server* server) : ACommand(server, false) {}
User::~User() {}


// sintax: USER <username> <hostname> <servername> :<realname>
void    User::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    if (_is_already_registered(client))
        return;

    client->set_realname(_get_realname(args));

    client->set_username(args[0]);

    _set_client_state(client);
    std::cout << "SUCCEDED USER" << std::endl;
}

bool User::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "USER::Validate parameters..." << std::endl;
    if (args.size() > 3 && !args[0].empty())
        return true;
    ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("USER")));
    return false;
}

std::string User::_get_realname(std::vector<std::string>& args) {
    std::cout << "USER::Getting real name..." << std::endl;
    std::string realname = args[3];
    if (realname[0] == ':')
        realname = realname.substr(1);

    for (size_t i = 4; i < args.size(); ++i)
        realname += " " + args[i];
    
    return realname;
}

void User::_set_client_state(Client* client) {
    std::cout << "USER::Setting register state..." << std::endl;
    if (client->get_state() != LOGGED_IN || client->get_nickname().empty())
        return;

    _set_registered(client);
}

bool User::_is_username_taken(const std::string& username, Client* client) {
    std::cout << "USER::Validate if username is already in use..." << std::endl;
    if (!_server->get_client(username))
        return false;
    ClientService::send_message(client, ERR_NICKNAMEINUSE(client->get_nickname(), client->get_username()));
    return true;
}
