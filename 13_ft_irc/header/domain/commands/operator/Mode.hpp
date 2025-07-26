#ifndef MODE_HPP
# define MODE_HPP

# include "ACommand.hpp"


class Mode : public ACommand {
    private:
        bool        _has_valid_parameters(Client* client, const std::vector<std::string>& args);
        void        _process_modes(Client* client, std::vector<std::string> args, Channel* channel);
        void        _send_active_modes(Client* client, Channel* channel);
        void        _set_mode_t(Client* client, Channel* channel, bool enable_mode);
        void        _set_mode_i(Client* client, Channel* channel, bool enable_mode);
        void        _set_mode_l(Client* client, Channel* channel, bool enable_mode, std::vector<std::string>& args);
        void        _set_mode_k(Client* client, Channel* channel, bool enable_mode, std::vector<std::string>& args);
        void        _set_mode_o(Client* client, Channel* channel, bool enable_mode, std::vector<std::string>& args);


    public:
        Mode(Server* server);
        ~Mode();

        void execute(Client* client, std::vector<std::string> args);
};

#endif
