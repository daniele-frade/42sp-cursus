#pragma once

#ifndef CLIENTSERVICE_HPP
# define CLIENTSERVICE_HPP

# include <vector>
# include <string>
# include <iostream>


class Channel;
class Client;

class ClientService {
    private:
        static void         _update_client_channel(Client* client, Channel* channel);
        static void         _broadcast_join_message(Client* client, Channel* channel);
        static void         _broadcast_part_message(Client* client, Channel* channel);

    public:
        static void         send_message(Client* client, const std::string message);
        static void         reply_message(Client* client, const std::string& reply);

        static void         join_channel(Client* client, Channel* channel);
        static void         leave_channel(Client* client, Channel* channel);
        static void         kicked_from_channel(Client* client, Client* target, Channel* channel, std::string reason);
};

#endif