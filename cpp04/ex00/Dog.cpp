#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const std::string type) : Animal(type)
{
    std::cout << "Dog constructor for the type " << _type << " called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Animal assignment constructor called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }

    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog deconstructor for " << _type << " called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "wal!! wal!!" << std::endl;
}

std::string Dog::getType() const
{
    return _type;
}

void Dog::setType(const std::string type)
{
    _type = type;
}
