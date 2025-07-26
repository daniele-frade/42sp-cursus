#ifndef NAMES_HPP
# define NAMES_HPP

# include "ACommand.hpp"


class Names : public ACommand {
    private:
      bool            _has_valid_parameters(Client* client, const std::vector<std::string>& args);
      std::string     _get_client_info(Channel* channel);

    public:
        Names(Server* server);
        ~Names();

        void execute(Client* client, std::vector<std::string> args);
};

#endif