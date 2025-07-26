#ifndef WHO_HPP
# define WHO_HPP

# include "ACommand.hpp"

class Who : public ACommand {
    private:
      bool          _has_valid_parameters(Client* client, const std::vector<std::string>& args);
      std::string   _get_user_info(Client* client, Channel* channel);

    public:
        Who(Server* server);
        ~Who();

        void execute(Client* client, std::vector<std::string> args);
};

#endif