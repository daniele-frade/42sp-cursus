#ifndef JOIN_HPP
# define JOIN_HPP

# include "ACommand.hpp"

class Join : public ACommand {
    private:
        bool        _has_valid_parameters(Client* client, const std::vector<std::string>& args);
        bool        _is_already_in_channel(Client* client);
        bool        _is_channel_full(Channel* channel, Client* client, const std::string& name);
        bool        _is_channel_key_valid(Channel* channel, Client* client, const std::string& pass, std::string name);
        bool        _is_guest(Channel* channel, Client* client, const std::string& name);

        void        _create_channel(std::string& channel_name, Client* client);
        void        _join_channel(std::string& channel_name, Client* client, std::string pass);
        void        _send_client_list(Channel* channel, Client* client);

    public:
        Join(Server* server);
        ~Join();

        void execute(Client* client, std::vector<std::string> args);
};

#endif
