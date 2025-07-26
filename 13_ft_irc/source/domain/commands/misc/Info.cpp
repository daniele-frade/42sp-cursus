#include "commands/misc/Info.hpp"
#include "ClientService.hpp"
#include "Client.hpp"
#include "Macros.hpp"


Info::Info(Server* server) : ACommand(server, false) {}
Info::~Info() {}


// syntax: INFO
void Info::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    ClientService::send_message(client, RPL_INFO(client->get_nickname(), "ft_irc v1.0 by inwagner, maalexan and dfrade"));
    ClientService::send_message(client, RPL_ENDOFINFO(client->get_nickname()));
}

bool Info::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "INFO::Validate parameters..." << std::endl;
    if (args.empty())
        return true;
    ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("INFO")));
    return false;
}
