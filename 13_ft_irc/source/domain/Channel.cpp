#include "Channel.hpp"
#include "Client.hpp"
#include <ctime>
#include <sstream>

Channel::Channel(Client* admin, const std::string& name) :
        _name(name),
        _admin(admin),
        _created(std::make_pair(admin->get_nickname(), _get_time())),
        _operators(std::make_pair(false, std::set<Client*>())),
        _guests(std::make_pair(false, std::set<Client*>())),
        _topic(std::make_pair(false, "")),
        _key(std::make_pair(false, "")),
        _limit(std::make_pair(false, 0)),
        _topic_restriction(false) {}

Channel::~Channel() {}

std::string                 Channel::get_name() const { return _name; }
Client*                     Channel::get_admin() const { return _admin; }
std::set<Client*>&          Channel::get_clients() { return _clients; }
std::map<Client*, int>&     Channel::get_black_list() { return _black_list; }


std::pair<bool, std::set<Client*> >&     Channel::get_operators() { return _operators; }
std::pair<bool, std::set<Client*> >&     Channel::get_guests() { return _guests; }
std::pair<bool, std::string>&            Channel::get_topic() { return _topic; }
std::pair<bool, std::string>&            Channel::get_key() { return _key; }
std::pair<bool, int>&                    Channel::get_limit() { return _limit; }
bool                                     Channel::has_topic_protection() { return _topic_restriction; }

void Channel::set_admin(Client* admin) { _admin = admin; }
void Channel::set_name(const std::string& name) { _name = name; }

void Channel::set_operators(bool state) { _operators.first = state; }
void Channel::set_guests(bool state) { _guests.first = state; }
void Channel::set_key(bool state, const std::string& key) { _key.first = state; _key.second = key; }
void Channel::set_limit(bool state, int limit) { _limit.first = state; _limit.second = limit; }

void Channel::set_topic(bool state, const std::string& topic, const std::string& creator) {
    _topic.first = state;
    _topic.second = topic;
    _created = (std::make_pair(creator, _get_time()));
}

void Channel::set_topic_protection(bool state) { 
    _topic_restriction = state;
}

Client* Channel::get_operator(Client* target) {
    if (_operators.first && _operators.second.find(target) != _operators.second.end())
        return target;
    return NULL;
}

Client* Channel::get_guest(Client* target) {
    if (_guests.first && _guests.second.find(target) != _guests.second.end())
        return target;
    return NULL;
}

std::string Channel::get_creator() {
    return _created.first;
}

std::string Channel::get_creation() {
    return _created.second;
}

void Channel::add_to_black_list(Client* client) {
    _black_list.find(client) != _black_list.end() 
        ? _black_list[client] += 1 
        : _black_list[client] = 1;
}

std::string Channel::get_active_modes() {
    std::string modes = "+nq";

    if (has_topic_protection())
        modes += "t";
    if (_guests.first)
        modes += "i";
    if (_limit.first)
        modes += "l";
    if (_key.first)
        modes += "k";
    if (!_operators.second.empty())
        modes += "o";

    return modes;
}

std::string Channel::get_mode_params(Client* client) {
    std::string         params;
    std::stringstream   ss;

    if (_limit.first) {
        ss << _limit.second;
        params += ss.str();
    }

    if (_key.first && (client == get_admin() || get_operator(client))) {
        if (!params.empty()) {
            params += " ";
        }
        params += _key.second;
    }

    return params;
}


std::string Channel::_get_time() {
    std::time_t now = std::time(NULL);
    std::ostringstream oss;
    oss << now;
    return oss.str();
}

void Channel::add_to_clients(Client* client) { _clients.insert(client); }
void Channel::add_to_guests(Client* client) { _guests.second.insert(client); }
void Channel::add_to_operators(Client* client) { _operators.second.insert(client); }

void Channel::remove_from_clients(Client* client) { _clients.erase(client); }
void Channel::remove_from_guests(Client* client) { _guests.second.erase(client); }
void Channel::remove_from_operators(Client* client) { _operators.second.erase(client); }
