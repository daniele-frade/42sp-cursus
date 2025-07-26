#ifndef IMULTIPLEXER_HPP
# define IMULTIPLEXER_HPP

# include <string>


class CommandHandler;
class Client;

class IMultiplexer
{
    public:
        virtual ~IMultiplexer() {}

        virtual int                         get_epoll_fd() const = 0;
        virtual Client*                     get_client(std::string target) = 0;
        virtual std::map<int, Client*>&     get_clients() = 0;

        virtual void    subscribe_fd_for_monitoring(int fd) = 0;
        virtual void    unsubscribe_fd_for_monitoring(int fd) = 0;

        virtual int     check_for_events() = 0;
        virtual void    handle_events(int total_events, CommandHandler* handler) = 0;

        virtual int     connect_client(int server_fd) = 0;
        virtual void    disconnect_client(int client_fd) = 0;
        virtual void    handle_client(int client_fd, CommandHandler* handler) = 0;

        virtual std::string    read_client_message(int client_fd) = 0;


        virtual void    handle_read_event(int fd) = 0;
        virtual void    handle_write_event(int fd) = 0;
        virtual void    handle_error_event(int fd) = 0;
        virtual void    handle_hangup_event(int fd) = 0;
};

#endif
