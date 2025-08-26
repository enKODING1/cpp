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
