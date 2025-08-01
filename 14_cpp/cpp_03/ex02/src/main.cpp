#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << "==============================ScavTrap Test=============================="<< std::endl;
    std::cout << "***Instantiating a ScavTrap object using the default constructor:" << std::endl;
	ScavTrap myDefaultScavTrap;
	std::cout << std::endl;

    std::cout << "***Instantiating a ScavTrap object using the parameterized constructor:" << std::endl;
	ScavTrap scavTrapNamed("MyScav");
	std::cout << std::endl;
	
	std::cout << "***Testing ScavTrap's methods: "<< std::endl;
    scavTrapNamed.attack("target1");
    scavTrapNamed.takeDamage(3);
    scavTrapNamed.beRepaired(5);
    scavTrapNamed.attack("target2");
    scavTrapNamed.takeDamage(10);
    scavTrapNamed.beRepaired(3);
    scavTrapNamed.guardGate();
	std::cout << std::endl;

	std::cout << "***Instantiating a ScavTrap object using the copy constructor:"<< std::endl;
    ScavTrap scavtrapCopy = scavTrapNamed;
	std::cout << std::endl;

    std::cout << "***Testing the ScavTrap object using the copy assignment operator:" << std::endl;
    ScavTrap scavTrapAssigned;
    scavTrapAssigned = scavTrapNamed;
    std::cout << std::endl;

    std::cout << "==============================FragTrap Test=============================="<< std::endl;
    std::cout << "***Instantiating a FragTrap object using the default constructor:" << std::endl;
	FragTrap myDefaultFragTrap;
	std::cout << std::endl;

    std::cout << "***Instantiating a FragTrap object using the parameterized constructor:" << std::endl;
	FragTrap fragTrapNamed("MyFrag");
	std::cout << std::endl;
	
	std::cout << "***Testing FragTrap's methods: "<< std::endl;
    fragTrapNamed.highFivesGuys();
	std::cout << std::endl;

	std::cout << "***Instantiating a FragTrap object using the copy constructor:"<< std::endl;
    FragTrap fragtrapCopy = fragTrapNamed;
	std::cout << std::endl;

    std::cout << "***Testing the FragTrap object using the copy assignment operator:" << std::endl;
    FragTrap fragTrapAssigned;
    fragTrapAssigned = fragTrapNamed;
    std::cout << std::endl;

    return 0;
}
