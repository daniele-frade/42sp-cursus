#ifndef USER_HPP
# define USER_HPP

# include "ACommand.hpp"


class User : public ACommand {
    private:
        bool            _has_valid_parameters(Client* client, const std::vector<std::string>& args);
        std::string     _get_realname(std::vector<std::string>& args);
        void            _set_client_state(Client* client);
        bool            _is_username_taken(const std::string& username, Client* client);

    public:
        User(Server* server);
        ~User();

        void execute(Client* client, std::vector<std::string> args);
};

#endif
