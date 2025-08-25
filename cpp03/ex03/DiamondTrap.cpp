#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    std::cout << "DiamondTrap constructor for the name " << _name << " called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap assignment constructor called" << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
    }

    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap deconstructor for " << _name << " called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name is " << _name << std::endl;
    std::cout << "CrapTrap name is " << ClapTrap::_name << std::endl;
}