#pragma once

#ifndef MULTIPLEXER_HPP
# define MULTIPLEXER_HPP

# include <iostream>
# include <errno.h>
# include <sys/epoll.h>
# include <unistd.h>
# include <netinet/in.h>
# include <cstring>
# include <map>
# include <netdb.h>

# include "interfaces/IMultiplexer.hpp"
#include "Constants.hpp"

class Client;
class CommandHandler;

class Multiplexer : public IMultiplexer {
    private:
        int                         _server_fd;
        int                         _epoll_fd;
        epoll_event                 _events[MAX_EVENTS];
        std::map<int, Client*>      _clients;
        std::map<int, std::string>  _client_buffers;


        int     _accept_connection(int server_fd, sockaddr_in* addr, socklen_t* size);
        Client* _create_client(int client_fd, const sockaddr_in& addr);
        std::string _get_client_hostname(const struct in_addr& client_ip);

    public:
        Multiplexer(int server_fd);
        ~Multiplexer();

        int                         get_epoll_fd() const;
        Client*                     get_client(std::string target);
        std::map<int, Client*>&     get_clients();

        void    subscribe_fd_for_monitoring(int fd);
        void    unsubscribe_fd_for_monitoring(int fd);

        int     check_for_events();
        void    handle_events(int total_events, CommandHandler* handler);
        

        int     connect_client(int server_fd);
        void    disconnect_client(int client_fd);
        void    handle_client(int client_fd, CommandHandler* handler);

        std::string     read_client_message(int client_fd);
        static void     send_client_message(int client_fd, const std::string& message);

        void    handle_read_event(int fd);
        void    handle_write_event(int fd);
        void    handle_error_event(int fd);
        void    handle_hangup_event(int fd);
};

#endif