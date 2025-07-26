#ifndef PONG_HPP
# define PONG_HPP

# include "ACommand.hpp"


class Pong : public ACommand {
    private:
      bool _has_valid_parameters(Client* client, const std::vector<std::string>& args);

    public:
        Pong(Server* server);
        ~Pong();

        void execute(Client* client, std::vector<std::string> args);
};

#endif