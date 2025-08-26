#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const std::string type) : Animal(type)
{
    std::cout << "Dog constructor for the type " << _type << " called" << std::endl;
    _brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Animal assignment constructor called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
        if (_brain != NULL)
            delete _brain;
        _brain = new Brain(*other._brain);
    }

    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog deconstructor for " << _type << " called" << std::endl;
    delete _brain;
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

Brain &Dog::getBrain() const
{
    return *_brain;
}

void Dog::setBrain(Brain brain)
{
    *_brain = brain;
}