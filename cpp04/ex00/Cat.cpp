#include "Cat.hpp"
#include "Animal.hpp"

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