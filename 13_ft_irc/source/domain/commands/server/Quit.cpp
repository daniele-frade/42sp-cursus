#include "commands/server/Quit.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "ClientService.hpp"
#include "ChannelService.hpp"
#include "IMultiplexer.hpp"
#include "Macros.hpp"
#include "Server.hpp"


Quit::Quit(Server* server) : ACommand(server, false) {}
Quit::~Quit() {}


// syntax: QUIT :<message>
void Quit::execute(Client* client, std::vector<std::string> args) {
    std::string reason;

    if (args.empty()) {
        reason = "";
    } else {
        for (size_t i = 0; i < args.size(); ++i) {
            if (i > 0)
                reason += " ";
            reason += args[i];
        }
        if (!reason.empty() && reason[0] == ':')
            reason = reason.substr(1);
    }

    ClientService::send_message(client, RPL_QUIT(client->get_info(), reason));
    IMultiplexer* multiplexer = _server->get_multiplexer();
    multiplexer->disconnect_client(client->get_fd());
    std::cout << "SUCCEDED QUIT" << std::endl;
}


bool Quit::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    (void)client;
    (void)args;
    return true;
}
