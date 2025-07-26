#ifndef HELP_HPP
# define HELP_HPP

# include "ACommand.hpp"


class Help : public ACommand {
    private:
      bool _has_valid_parameters(Client* client, const std::vector<std::string>& args);

    public:
        Help(Server* server);
        ~Help();

        void execute(Client* client, std::vector<std::string> args);
};

#endif