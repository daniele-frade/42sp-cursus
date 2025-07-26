#include "commands/misc/Pong.hpp"
#include "ClientService.hpp"
#include "Client.hpp"
#include "Macros.hpp"


Pong::Pong(Server* server) : ACommand(server, false) {}
Pong::~Pong() {}


// syntax: PONG <server_addr>
void Pong::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    ClientService::send_message(client, RPL_PING(args[0]));
}

bool Pong::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "PONG::Validate parameters..." << std::endl;
    if (args.size() == 1 || args.empty())
        return true;
    ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("PONG")));
    return false;
}
