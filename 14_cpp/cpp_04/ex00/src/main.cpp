#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "Creating a Dog and a Cat objects" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << "Animal type from a dog object: " << dog->getType() << std::endl;
    dog->makeSound(); // Should output "Woof Woof!"
    std::cout << "Animal type from a cat object: " << cat->getType() << std::endl;
    cat->makeSound(); // Should output "Meow Meow!"
    std::cout << std::endl;
   
    std::cout << "Creating a WrongAnimal and a WrongCat objects" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "Animal type from a wrongAnimal object: " << wrongAnimal->getType() << std::endl;
     wrongAnimal->makeSound();
    std::cout << "Animal type from a wrongCat object: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    std::cout << std::endl;

    // Clean up
    delete dog;
    delete cat;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
