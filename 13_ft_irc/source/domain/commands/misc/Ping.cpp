#include "commands/misc/Ping.hpp"
#include "ClientService.hpp"
#include "Client.hpp"
#include "Macros.hpp"


Ping::Ping(Server* server) : ACommand(server, false) {}
Ping::~Ping() {}


// syntax: PING <server_addr>
void Ping::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    ClientService::send_message(client, RPL_PING(args[0]));
}

bool Ping::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "PING::Validate parameters..." << std::endl;
    if (args.size() == 1 || args.empty())
        return true;
    ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("PING")));
    return false;
}
