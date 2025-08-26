#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    int numAnimals = 4;
    Animal *animals[numAnimals];
    Dog dog1;
    Dog dog2(dog1);

    std::cout << std::endl
              << "---constructor---" << std::endl;
    for (int i = 0; i < numAnimals / 2; ++i)
        animals[i] = new Dog();
    for (int i = numAnimals / 2; i < numAnimals; ++i)
        animals[i] = new Cat();

    /* memory check */
    std::cout << std::endl
              << "---check---" << std::endl;
    std::cout << "dog1 brain address: " << &dog1.getBrain() << std::endl;
    std::cout << "dog2 brain address: " << &dog2.getBrain() << std::endl;

    /* deconstructur */
    std::cout << std::endl
              << "---deconstructor---" << std::endl;
    for (int i = 0; i < numAnimals; ++i)
        delete animals[i];
    return 0;
}