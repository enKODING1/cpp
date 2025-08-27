#include "AMateria.hpp"

AMateria::AMateria() : _type("Amateria")
{
    std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
    *this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        _type = other._type;
    }

    return *this;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "Animal constructor for the type " << type << " called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria deconstructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
    return _type;
}