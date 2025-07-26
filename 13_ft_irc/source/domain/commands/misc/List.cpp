#include "commands/misc/List.hpp"
#include "ClientService.hpp"
#include "ChannelService.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "Macros.hpp"
#include "Server.hpp"
#include <sstream> 


List::List(Server* server) : ACommand(server, false) {}
List::~List() {}


// syntax: LIST
void List::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    std::set<Channel*> channels = _server->get_channels();
    std::string nickname = client->get_nickname();

    for (std::set<Channel*>::iterator it = channels.begin(); it != channels.end(); ++it) {
        std::string name = (*it)->get_name();
        std::string topic = (*it)->get_topic().second;

        int num = ChannelService::get_total_clients(*it);
        std::stringstream ss;
        ss << num;
        std::string clientcount = ss.str();

        ClientService::send_message(client, RPL_LIST(client->get_nickname(), name, clientcount, topic));
    }
    ClientService::send_message(client, RPL_LISTEND(client->get_nickname()));
}

bool List::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "LIST::Validate parameters..." << std::endl;
    if (args.empty())
        return true;
    ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("LIST")));
    return false;
}
