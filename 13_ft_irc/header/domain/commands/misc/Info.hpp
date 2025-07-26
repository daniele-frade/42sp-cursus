#ifndef INFO_HPP
# define INFO_HPP

# include "ACommand.hpp"


class Info : public ACommand {
    private:
      bool _has_valid_parameters(Client* client, const std::vector<std::string>& args);

    public:
        Info(Server* server);
        ~Info();

        void execute(Client* client, std::vector<std::string> args);
};

#endif