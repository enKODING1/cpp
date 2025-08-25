#include "Animal.hpp"

/*
 Animal Class
*/
Animal::Animal() : _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string type) : _type(type)
{
    std::cout << "Animal constructor for the type " << type << " called" << std::endl;
}

Animal::Animal(const Animal &other) : _type("Animal")
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal assignment constructor called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }

    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal deconstructor for " << _type << " called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "not set.." << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}

void Animal::setType(const std::string type)
{
    _type = type;
}

/*
    Dog Class
*/
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

/*
 Cat Class
*/

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const std::string type) : Animal(type)
{
    std::cout << "Cat constructor for the type " << _type << " called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat assignment constructor called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }

    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat deconstructor for " << _type << " called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "meow!! meow!!" << std::endl;
}

std::string Cat::getType() const
{
    return _type;
}

void Cat::setType(const std::string type)
{
    _type = type;
}