#include "ClapTrap.hpp"

int main() {
    std::cout << "==============================ClapTrap Test==============================" << std::endl;
    std::cout << "***Instantiating a ClapTrap object using the default constructor:" << std::endl;
	ClapTrap myDefaultClapTrap;
	std::cout << std::endl;

    std::cout << "***Instantiating a ClapTrap object using the parameterized constructor:" << std::endl;
	ClapTrap clapTrapNamed("MyClap");
	std::cout << std::endl;
	
	std::cout << "***Testing ClapTrap's methods: "<< std::endl;
    clapTrapNamed.attack("target1");
    clapTrapNamed.takeDamage(3);
    clapTrapNamed.beRepaired(5);
    clapTrapNamed.attack("target2");
    clapTrapNamed.takeDamage(10);
    clapTrapNamed.beRepaired(3);
	std::cout << std::endl;

	std::cout << "***Instantiating a ClapTrap object using the copy constructor:"<< std::endl;
    ClapTrap claptrapCopy = clapTrapNamed;
	std::cout << std::endl;

    std::cout << "***Testing the ClapTrap object using the copy assignment operator:" << std::endl;
    ClapTrap clapTrapAssigned;
    clapTrapAssigned = clapTrapNamed;
    std::cout << std::endl;

    return 0;
}
