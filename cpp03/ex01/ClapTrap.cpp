#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("anonymous"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap constructor for the name " << _name << " called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment constructor called" << std::endl;
    if (this != &other)
    {
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        _name = other._name;
    }

    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap deconstructor for " << _name << " called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack, current HP: " << _hitPoints << std::endl;
    }
    else if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack, current EnergePoints: " << _energyPoints << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints < amount && _hitPoints != 0)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " died from an attack, current HP: " << _hitPoints << std::endl;
    }
    else if (_hitPoints > amount || _hitPoints == amount)
    {
        _hitPoints = _hitPoints - amount;
        std::cout << "ClapTrap " << _name << " take " << amount << " damage from an attack, current HP: " << _hitPoints << std::endl;
    }
    else if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already died" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't repair, current EnergyPoints: " << _energyPoints << std::endl;
    }
    else if (_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't repair, current HitPoints: " << _hitPoints << std::endl;
    }
    else if (_hitPoints == 10)
    {
        std::cout << "ClapTrap " << _name << " hp is arleady max, current HP: " << _hitPoints << std::endl;
    }
    else if (_hitPoints > 0)
    {
        _energyPoints--;
        if (_hitPoints + amount >= 10)
            _hitPoints = 10;
        else
            _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repaired itself for " << amount << " HP , current HP: " << _hitPoints << std::endl;
    }
}