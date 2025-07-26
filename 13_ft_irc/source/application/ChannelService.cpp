#include "ChannelService.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "ClientService.hpp"
#include "Macros.hpp"
#include "Constants.hpp"


void ChannelService::broadcast(Channel* channel, const std::string& message, Client* exclude) {
    std::cout << "ChannelService::Broadcast annoucing..." << std::endl;
    std::set<Client*>& clients = channel->get_clients();
    for (std::set<Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
        if (*it != exclude) {
            ClientService::send_message(*it, message);
        }
    }
}

bool ChannelService::add_client(Channel* channel, Client* client) {
    std::cout << "ChannelService::Adding client..." << std::endl;
    if (_is_client_banned(channel, client))
        return false;

    channel->add_to_clients(client);
    _announce_client_join(channel, client);
    std::cout << "ChannelService::Client added." << std::endl;
    return true;
}

void ChannelService::remove_client(Channel* channel, Client* client) {
    std::cout << "ChannelService::Removing client..." << std::endl;
    channel->remove_from_clients(client);
    channel->remove_from_guests(client);
    channel->remove_from_operators(client);

    _change_admin_if_needed(channel, client);
    std::cout << "ChannelService::Client removed." << std::endl;
}

void ChannelService::kick_client(Channel* channel, Client* client, Client* target, const std::string& reason) {
    std::cout << "ChannelService::Kicking client..." << std::endl;
    _announce_client_kick(channel, client, target, reason);
    channel->add_to_black_list(target);
    channel->remove_from_clients(target);
    channel->remove_from_guests(target);
    channel->remove_from_operators(target);
    remove_client(channel, target);

    std::cout << "ChannelService::Client kicked." << std::endl;
}

std::vector<std::string>    ChannelService::get_nicknames(Channel* channel) {
    std::set<Client*>       clients = channel->get_clients();

    std::vector<std::string> nicknames;
    for (std::set<Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
        Client* client = *it;

        std::string nick = (client == channel->get_admin() ? "admin: " : "user: ") + client->get_nickname();
        nicknames.push_back(nick);
    }

    return nicknames;
}

int ChannelService::get_total_clients(Channel* channel) {
    std::set<Client*>       clients = channel->get_clients();
    return clients.size(); 
}

bool ChannelService::_is_client_banned(Channel* channel, Client* client) {
    std::cout << "ChannelService::Validate if client is banned..." << std::endl;
    std::map<Client*, int>& black_list = channel->get_black_list();
    std::map<Client*, int>::iterator it = black_list.find(client);

    if (it == black_list.end() || it->second < MAX_BLACKLIST_VIOLATIONS)
        return false;

    ClientService::send_message(client, ERR_BANNEDFROMCHAN(client->get_nickname(), channel->get_name()));
    return true;
}

void ChannelService::_change_admin_if_needed(Channel* channel, Client* client) {
    std::cout << "ChannelService::Validate if change admin is needed..." << std::endl;
    if (client != channel->get_admin())
        return;

    if (channel->get_operators().first) {
        std::cout << "ChannelService::Searching for operator to set new admin..." << std::endl;
        std::set<Client*>& operators = channel->get_operators().second;
        if (!operators.empty()) {
            Client* new_admin = *operators.begin();
            channel->set_admin(new_admin);
            channel->remove_from_operators(new_admin);
            _announce_admin_change(channel, new_admin);
            return;
        }
    }

    std::set<Client*>& clients = channel->get_clients();
    if (!clients.empty()) {
        std::cout << "ChannelService::Searching for client to set new admin..." << std::endl;
        std::set<Client*>::iterator it = clients.begin();
        Client* new_admin = *it;
        channel->set_admin(new_admin);
        _announce_admin_change(channel, new_admin);
        return;
    }

    std::cout << "ChannelService::Channel is empty." << std::endl;
    channel->set_admin(NULL);
}

void ChannelService::_announce_client_join(Channel* channel, Client* client) {
    std::string announcer = ":";
    std::string nickname_client = client->get_nickname();
    std::string channel_name = channel->get_name();
}

void ChannelService::_announce_admin_change(Channel* channel, Client* client) {
    std::string nickname_client = client->get_nickname();
    std::string channel_name = channel->get_name();

    std::set<Client*>& clients = channel->get_clients();
    for (std::set<Client*>::iterator it = clients.begin(); it != clients.end(); ++it) {
        ClientService::send_message(*it, MESSAGE_ADMIN_CHANGE((*it)->get_nickname(), channel_name, nickname_client));
    }
}

void ChannelService::_announce_client_kick(Channel* channel, Client* client, Client* target, const std::string& reason) {
    std::string announcer = ":";
    std::string nickname_client = client->get_nickname();
    std::string nickname_target = target->get_nickname();
    std::string channel_name = channel->get_name();
    broadcast(channel, announcer + MESSAGE_CLIENT_KICK(channel_name, nickname_client, nickname_target, reason));
}
