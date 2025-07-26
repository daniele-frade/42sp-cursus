#ifndef COMMAND_HANDLER_HPP
# define COMMAND_HANDLER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <map>


class Server;
class Client;
class ACommand;

class CommandHandler {
    private:
        Server*                                 _server;
        std::map<std::string, ACommand *>       _commands;

        std::string     _trim(const std::string& str);

    public:
        CommandHandler(Server* server);
        ~CommandHandler();

        void    handle_command(Client* client, const std::string& message);
};

#endif