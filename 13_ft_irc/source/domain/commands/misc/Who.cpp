#include "commands/misc/Who.hpp"
#include "ClientService.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "Macros.hpp"
#include "Server.hpp"


Who::Who(Server* server) : ACommand(server, false) {}
Who::~Who() {}


// syntax: WHO #<channel>
void Who::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    std::string channel_name = args[0];
    if (channel_name.at(0) != '#') {
        ClientService::send_message(client, ERR_NOSUCHCHANNEL(client->get_nickname(), channel_name));
        return;
    }

    Channel* channel = _server->get_channel(channel_name);
    if (channel == NULL) {
        ClientService::send_message(client, ERR_NOSUCHCHANNEL(client->get_nickname(), channel_name));
        return;
    }

    std::set<Client*> clients = channel->get_clients();
    for (std::set<Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
        std::string user_info = _get_user_info(*it, channel);
        ClientService::send_message(client, RPL_WHOREPLY(client->get_nickname(), channel_name, user_info));
    }

    ClientService::send_message(client, RPL_ENDOFWHO(client->get_nickname(), channel_name));
}

bool Who::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "WHO::Validate parameters..." << std::endl;
    if (args.size() == 1)
        return true;
    ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("WHO")));
    return false;
}

std::string Who::_get_user_info(Client* client, Channel* channel) {
    std::string info =  client->get_username() + " " + client->get_hostname() + " " +
                        client->get_info() + " ft_irc " +
                        client->get_nickname() + " H" +
                        (channel->get_operators().second.find(client) != channel->get_operators().second.end() ? "*" : "" ) + 
                        " :0 " + client->get_realname();

    return info;
}
