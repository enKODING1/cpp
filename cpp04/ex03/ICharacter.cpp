#include "ICharacter.hpp"

/**
 * ICharacter
 * */
ICharacter::~ICharacter()
{
    std::cout << "ICharacter deconstructor called" << std::endl;
}

/**
 * Character
 */
Character::Character() : ICharacter(), _name("character")
{
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character &other)
{
    *this = other;
}

Character::Character(std::string name) : ICharacter(), _name(name)
{
    std::cout << "Character constructor for the name " << name << " called" << std::endl;
}

Character &Character::operator=(const Character &other)
{
    if (this != &other)
    {
    }

    return *this;
}

Character::~Character()
{
    std::cout << "Character deconstructor called" << std::endl;
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
}

void Character::unequip(int idx)
{
}

void Character::use(int idx, ICharacter &target)
{
}