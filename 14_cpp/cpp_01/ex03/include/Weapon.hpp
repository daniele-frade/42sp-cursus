#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;

public:
    Weapon(const std::string type);
	~Weapon();
    std::string const &getType() const;
    void setType(std::string type);
};

#endif
