#pragma once

#ifndef SOCKET_HPP
# define SOCKET_HPP

# include <unistd.h>
# include <cstring>
# include <fcntl.h>
# include <arpa/inet.h>
# include <stdexcept>

# include "interfaces/ISocket.hpp"


class Socket : public ISocket {
    private:
        int                 _socket_fd;
        struct sockaddr_in  _address;
        int                 _max_connections;

        void    _create_socket();
        void    _configure_socket();
        void    _set_non_blocking();
        void    _configure_address(const std::string& host, int port);
        void    _bind_socket_to_address();
        void    _set_listening();

    public:
        Socket(const std::string& host, int port);
        ~Socket();

        int     get_fd() const;
};

#endif
