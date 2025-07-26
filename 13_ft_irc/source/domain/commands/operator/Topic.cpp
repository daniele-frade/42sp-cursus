#include "commands/operator/Topic.hpp"
#include "Channel.hpp"
#include "Client.hpp"
#include "ClientService.hpp"
#include "ChannelService.hpp"
#include "Macros.hpp"
#include "Server.hpp"


Topic::Topic(Server* server) : ACommand(server, true) {}
Topic::~Topic() {}


// syntax: TOPIC #<channel> :<new_topic>
//         TOPIC #<channel>
void Topic::execute(Client* client, std::vector<std::string> args) {
    if (!_has_valid_parameters(client, args))
        return;

    std::string channel_name = args[0];
    if (channel_name.at(0) != '#') {
        ClientService::send_message(client, ERR_NOSUCHCHANNEL(client->get_nickname(), channel_name));
        return;
    }

    Channel* channel = _server->get_channel(channel_name);
    if (!_is_valid_channel(client, channel, channel_name))
        return;

    if (args.size() == 1) {
        _send_current_topic(client, channel);
        std::cout << "SUCCEDED TOPIC" << std::endl;
        return;
    }

    if (!_is_on_channel(client, channel))
        return;

    if (channel->has_topic_protection() && !_has_channel_privileges(client, channel))
        return;

    _set_new_topic(client, channel, args);
    std::cout << "SUCCEDED TOPIC" << std::endl;
}

bool Topic::_has_valid_parameters(Client* client, const std::vector<std::string>& args) {
    std::cout << "TOPIC::Validate parameters..." << std::endl;
    if (args.empty()) {
        ClientService::send_message(client, ERR_NEEDMOREPARAMS(client->get_nickname(), std::string("TOPIC")));
        return false;
    }
    return true;
}

void Topic::_send_current_topic(Client* client, Channel* channel) {
    if (channel->get_topic().first) {
        ClientService::send_message(client, RPL_TOPIC(client->get_nickname(), channel->get_name(), channel->get_topic().second));
        ClientService::send_message(client, RPL_TOPICWHOTIME(client->get_nickname(), channel->get_name(), channel->get_creator(), channel->get_creation()));
        return;
    }
    ClientService::send_message(client, RPL_NOTOPIC(client->get_nickname(), channel->get_name()));
}

void Topic::_set_new_topic(Client* client, Channel* channel, const std::vector<std::string>& args) {
    std::cout << "TOPIC::Defining new topic description..." << std::endl;
          std::string topic = _extract_topic(args);
        channel->set_topic(true, topic, client->get_nickname());
        ChannelService::broadcast(channel, RPL_TOPIC(client->get_nickname(), channel->get_name(), channel->get_topic().second));
}

std::string Topic::_extract_topic(const std::vector<std::string>& args) {
    std::cout << "TOPIC::Extracting topic description..." << std::endl;
    std::string topic = "";
    if (args.size() >= 2 && (args[1][0] != ':' || args[1].size() > 1)) {
        for (size_t i = 1; i < args.size(); ++i) {
            topic.append(args[i]);
            if (i != args.size() - 1)
                topic.append(" ");
        }
    }
    return topic;
}
