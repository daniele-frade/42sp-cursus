#ifndef KICK_HPP
# define KICK_HPP

# include "ACommand.hpp"


class Kick : public ACommand {
    private:
        bool        _has_valid_parameters(Client* client, const std::vector<std::string>& args);
        bool        _kicking_admin(Client* client, Channel* channel, Client* target_client);
        bool        _kicking_self(Client* client, Channel* channel, Client* target_client);
        std::string _extract_reason(const std::vector<std::string>& args);

    public:
        Kick(Server* server);
        ~Kick();

        void execute(Client* client, std::vector<std::string> args);
};

#endif
