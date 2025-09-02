#include "Character.hpp"
#include "AMateria.hpp"

/**
 * Character
 */
Character::Character() : ICharacter(), _name("character")
{
    // std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character &other) : ICharacter(), _name(other._name)
{
    // std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

Character::Character(std::string name) : ICharacter(), _name(name)
{
    // std::cout << "Character constructor for the name " << name << " called" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (_inventory[i])
                delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }

    return *this;
}

Character::~Character()
{
    // std::cout << "Character deconstructor called" << std::endl;
    for (int i = 0; i < 4; i++)
        if (_inventory[i])
            delete _inventory[i];
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            return;
        }
    }
    std::cout << "Character " << _name << " has no more space in inventory" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (_inventory[idx])
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (_inventory[idx])
        _inventory[idx]->use(target);
}
