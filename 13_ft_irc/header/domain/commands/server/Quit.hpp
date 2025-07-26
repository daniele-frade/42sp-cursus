#ifndef QUIT_HPP
# define QUIT_HPP

# include "ACommand.hpp"


class Quit : public ACommand {
    private:
        bool        _has_valid_parameters(Client* client, const std::vector<std::string>& args);

    public:
        Quit(Server* server);
        ~Quit();

        void execute(Client* client, std::vector<std::string> args);
};

#endif
