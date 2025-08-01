#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {

    AAnimal test;

    std::cout << "=== Testing deep copy functionality with Dog ===" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Chase the ball");
    originalDog.getBrain()->setIdea(1, "Eat dinner");

    Dog copiedDog = originalDog;

    std::cout << "Original Dog's ideas: " << std::endl;
    std::cout << "Idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog.getBrain()->getIdea(1) << std::endl;

    std::cout << "Copied Dog's ideas: " << std::endl;
    std::cout << "Idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << copiedDog.getBrain()->getIdea(1) << std::endl;

    copiedDog.getBrain()->setIdea(0, "Sleep on the couch"); // Modifying the copy

    std::cout << "Modified Copied Dog's idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;

    return 0;
}
