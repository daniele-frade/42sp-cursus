#pragma once

#ifndef SERVER_HPP
# define SERVER_HPP

# include <string>
# include <set>
# include <map>
# include <ctime>


class CommandHandler;
class IMultiplexer;
class IVault;
class ISocket;
class Channel;
class Client;

class Server {
    private:
        bool                        _running;
        IVault*                     _vault;
        ISocket*                    _socket;
        IMultiplexer*               _multiplexer;
        std::set<Channel* >         _channels;
        CommandHandler*             _command_handler;
        std::string                 _datetime;
 
    public:
        Server(IVault* vault, ISocket* socket, IMultiplexer* multiplexer);
        ~Server();

        IMultiplexer*                   get_multiplexer() const;
        CommandHandler*                 get_command_handler() const;

        const std::set<Channel*>&       get_channels() const;
        Channel*                        get_channel(const std::string& name);

        const std::map<int, Client*>&   get_clients() const;
        Client*                         get_client(const std::string& name);

        const std::string&              get_datetime() const;

        void                            set_command_handler(CommandHandler* handler);

        void start();
        void stop();

        Channel*    create_channel(std::string name, Client* client);
        bool        is_valid_pass(std::string pass);
};

#endif
