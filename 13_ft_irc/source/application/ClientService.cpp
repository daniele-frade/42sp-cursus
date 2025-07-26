#include "ClientService.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "ChannelService.hpp"
#include "Multiplexer.hpp"
#include "Macros.hpp"


void ClientService::send_message(Client* client, const std::string message) {
    Multiplexer::send_client_message(client->get_fd(), message);
}

void ClientService::reply_message(Client* client, const std::string& reply) {
    send_message(client, ":" + client->get_info() + " " + reply);
}

void ClientService::join_channel(Client* client, Channel* channel) {
    std::cout << "ClientService::Joining to a channel..." << std::endl;
    _update_client_channel(client, channel);
    _broadcast_join_message(client, channel);
    std::cout << "ClientService::Client joined." << std::endl;
}

void ClientService::leave_channel(Client* client, Channel* channel) {
    std::cout << "ClientService::Leaving for a channel..." << std::endl;
    _update_client_channel(client, NULL);
    _broadcast_part_message(client, channel);
    std::cout << "ClientService::Client left." << std::endl;
}

void ClientService::kicked_from_channel(Client* client, Client* target, Channel* channel, std::string reason) {
    std::cout << "ClientService::Kicking from channel..." << std::endl;
    (void)client;
    (void)reason;
    (void)channel;
    _update_client_channel(target, NULL);
    std::cout << "ClientService::Client kicked." << std::endl;
}

void ClientService::_update_client_channel(Client* client, Channel* channel) {
    client->set_channel(channel);
}

void ClientService::_broadcast_join_message(Client* client, Channel* channel) {
    ChannelService::broadcast(channel, RPL_JOIN(client->get_info(), channel->get_name()));
}

void ClientService::_broadcast_part_message(Client* client, Channel* channel) {
    ClientService::send_message(client, RPL_PART(client->get_nickname(), channel->get_name()));
    ChannelService::broadcast(channel, RPL_PART(client->get_nickname(), channel->get_name()));
}
