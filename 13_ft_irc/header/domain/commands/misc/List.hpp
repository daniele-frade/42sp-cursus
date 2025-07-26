#ifndef LIST_HPP
# define LIST_HPP

# include "ACommand.hpp"


class List : public ACommand {
    private:
      bool _has_valid_parameters(Client* client, const std::vector<std::string>& args);

    public:
        List(Server* server);
        ~List();

        void execute(Client* client, std::vector<std::string> args);
};

#endif