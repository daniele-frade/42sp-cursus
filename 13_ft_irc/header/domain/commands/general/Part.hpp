#ifndef PART_HPP
# define PART_HPP

# include "ACommand.hpp"


class Part : public ACommand {
    private:
        bool        _has_valid_parameters(Client* client, const std::vector<std::string>& args);
        bool        _is_client_in_channel(Client* client, Channel* channel, const std::string& name);

    public:
        Part(Server* server);
        ~Part();

        void execute(Client* client, std::vector<std::string> args);
};

#endif
