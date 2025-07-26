#pragma once

#ifndef CHANNEL_SERVICE_HPP
# define CHANNEL_SERVICE_HPP

# include <set>
# include <vector>
# include <cstddef>
# include <string>
# include <iostream>


class Channel;
class Client;

class ChannelService {
    private:
        static void     _change_admin_if_needed(Channel* channel, Client* client);
        static bool     _is_client_banned(Channel* channel, Client* client);
        static void     _announce_client_join(Channel* channel, Client* client);
        static void     _announce_client_leave(Channel* channel, Client* client);
        static void     _announce_admin_change(Channel* channel, Client* client);
        static void     _announce_client_kick(Channel* channel, Client* client, Client* target, const std::string& reason);

    public:
        static void     broadcast(Channel* channel, const std::string& message, Client* exclude = NULL);

        static bool     add_client(Channel* channel, Client* client);
        static void     remove_client(Channel* channel, Client* client);
        static void     kick_client(Channel* channel, Client* client, Client* target, const std::string& reason);

        static std::vector<std::string> get_nicknames(Channel* channel);
        static int                      get_total_clients(Channel* channel);
};

#endif
