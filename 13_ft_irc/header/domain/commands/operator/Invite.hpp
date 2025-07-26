#ifndef INVITE_HPP
# define INVITE_HPP

# include "ACommand.hpp"


class Invite : public ACommand {
    private:
        bool        _has_valid_parameters(Client* client, const std::vector<std::string>& args);

    public:
        Invite(Server* server);
        ~Invite();

        void execute(Client* client, std::vector<std::string> args);
};

#endif
