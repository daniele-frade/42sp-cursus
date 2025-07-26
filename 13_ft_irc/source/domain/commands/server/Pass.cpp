#include "commands/server/Pass.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "ClientService.hpp"
#include "ChannelService.hpp"
#include "Macros.hpp"
#include "Server.hpp"


Pass::Pass(Server* server) : ACommand(server, false) {}
Pass::~Pass() {}


// syntax: PASS <password>
void    Pass::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    if (_is_already_registered(client))
        return;

    std::string password = args[0];
    if (!_is_password_valid(password)) {
        ClientService::send_message(client, ERR_PASSWDMISMATCH(client->get_nickname()));
        return;
    }

    client->set_state(LOGGED_IN);
    std::cout << "SUCCEDED PASS" << std::endl;
}


// Funções auxiliares

bool Pass::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "PASS::Validate parameters..." << std::endl;
    if (args.size() == 1)
        return true;
    ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("PASS")));
    return false;
}


bool Pass::_is_password_valid(const std::string& password) {
    return _server->is_valid_pass(password);
}
