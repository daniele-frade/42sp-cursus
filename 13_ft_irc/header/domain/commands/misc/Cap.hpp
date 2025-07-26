#ifndef CAP_HPP
# define CAP_HPP

# include "ACommand.hpp"


class Cap : public ACommand {
    private:
      bool _has_valid_parameters(Client* client, const std::vector<std::string>& args);

    public:
        Cap(Server* server);
        ~Cap();

        void execute(Client* client, std::vector<std::string> args);
};

#endif