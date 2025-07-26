#ifndef NOTICE_HPP
# define NOTICE_HPP

# include "ACommand.hpp"


class Notice : public ACommand {
    private:
        bool        _has_valid_parameters(Client* client, const std::vector<std::string>& args);
        std::string _build_message(const std::vector<std::string>& args);
        void        _handle_channel_message(Client* client, std::string& target, const std::string& message);
        void        _handle_client_message(Client* client, const std::string& target, const std::string& message);

    public:
        Notice(Server* server);
        ~Notice();

        void execute(Client* client, std::vector<std::string> args);
};

#endif