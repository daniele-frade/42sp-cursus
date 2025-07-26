#ifndef PING_HPP
# define PING_HPP

# include "ACommand.hpp"


class Ping : public ACommand {
    private:
      bool _has_valid_parameters(Client* client, const std::vector<std::string>& args);

    public:
        Ping(Server* server);
        ~Ping();

        void execute(Client* client, std::vector<std::string> args);
};

#endif