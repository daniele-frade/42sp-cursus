#pragma once

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <set>
# include <map>
# include <utility>
# include <algorithm>
# include <vector>
# include <string>


class Client;

class Channel {
    typedef std::vector<Client*>::iterator client_iterator;

    private:
        std::string             _name;
        Client*                 _admin;
        std::set<Client*>       _clients;
        std::map<Client*, int>  _black_list;
        std::pair<std::string, std::string> _created;

        std::pair<bool, std::set<Client*> >     _operators;
        std::pair<bool, std::set<Client*> >     _guests;
        std::pair<bool, std::string>            _topic;
        std::pair<bool, std::string>            _key;
        std::pair<bool, int>                    _limit;
        bool                                    _topic_restriction;

        std::string _get_time();

    public:
        Channel(Client* admin, const std::string& name);
        ~Channel();

        std::pair<bool, std::set<Client*> >&     get_operators();
        std::pair<bool, std::set<Client*> >&     get_guests();
        std::pair<bool, std::string>&            get_topic();
        std::pair<bool, std::string>&            get_key();
        std::pair<bool, int>&                    get_limit();
        bool                                     has_topic_protection();

        std::string                 get_name() const;
        Client*                     get_admin() const;
        std::set<Client*>&          get_clients();
        std::map<Client*, int>&     get_black_list();

        void                        set_name(const std::string& name);
        void                        set_admin(Client* admin);

        void                        set_operators(bool state);
        void                        set_guests(bool state);
        void                        set_topic(bool state, const std::string& topic, const std::string& creator);
        void                        set_key(bool state, const std::string& key);
        void                        set_limit(bool state, int limit);
        void                        set_topic_protection(bool state);

        Client*                     get_operator(Client* target);
        Client*                     get_guest(Client* target);

        void                        add_to_black_list(Client* client);
        void                        add_to_clients(Client* client);
        void                        add_to_guests(Client* client);
        void                        add_to_operators(Client* client);

        void                        remove_from_clients(Client* client);
        void                        remove_from_guests(Client* client);
        void                        remove_from_operators(Client* client);

        std::string                 get_creation();
        std::string                 get_creator();
        std::string                 get_active_modes();
        std::string                 get_mode_params(Client* client);
};

#endif
