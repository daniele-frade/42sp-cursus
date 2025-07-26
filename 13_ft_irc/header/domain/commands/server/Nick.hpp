#ifndef NICK_HPP
# define NICK_HPP

# include "ACommand.hpp"


class Nick : public ACommand {
    private:
        bool        _has_valid_parameters(Client* client, const std::vector<std::string>& args);
        bool        _is_nickname_taken(const std::string& nickname, Client* client);
        void        _set_client_state(Client* client);

    public:
        Nick(Server* server);
        ~Nick();

        void execute(Client* client, std::vector<std::string> args);
};

#endif
