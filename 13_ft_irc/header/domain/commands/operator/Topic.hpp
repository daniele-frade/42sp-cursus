#ifndef TOPIC_HPP
# define TOPIC_HPP

# include "ACommand.hpp"


class Topic : public ACommand {
    private:
        bool        _has_valid_parameters(Client* client, const std::vector<std::string>& args);
        std::string _extract_topic(const std::vector<std::string>& args);
        void        _set_new_topic(Client* client, Channel* channel, const std::vector<std::string>& args);
        void        _send_current_topic(Client* client, Channel* channel);

    public:
        Topic(Server* server);
        ~Topic();

        void execute(Client* client, std::vector<std::string> args);
};

#endif
