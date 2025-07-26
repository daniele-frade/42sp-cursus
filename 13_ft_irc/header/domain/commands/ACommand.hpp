#pragma once

#ifndef ACOMMAND_HPP
# define ACOMMAND_HPP

# include <vector>
# include <string>
# include <iostream>


class Channel;
class Client;
class Server;

class ACommand {
    protected:
        bool    _auth;
        Server*  _server;

        virtual bool    _has_valid_parameters(Client* client, const std::vector<std::string>& args) = 0;

        bool            _has_channel_privileges(Client* client, Channel* channel);

        bool            _is_valid_channel(Client* client, Channel* channel, std::string target);
        bool            _is_valid_client(Client* client, Client* dest, const std::string& dest_nickname);
        bool            _is_client_on_channel(Client* client, Channel* channel);

        bool            _is_already_registered(Client* client);
        bool            _is_on_channel(Client* client, Channel* channel);
        bool            _is_already_on_channel(Client* client, Client* dest, Channel* channel);

        void            _set_registered(Client* client);
        std::string     _get_prefix(Client* client, Channel* channel);
        
    public:
        ACommand(Server* server, bool auth = true);
        virtual ~ACommand();

        bool auth_required() const;

        virtual void execute(Client* client, std::vector<std::string> args) = 0;
};

#endif
