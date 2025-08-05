#include "HumanB.hpp"

HumanB::HumanB()
{
    name = "";
    weapon = Weapon("");
}

HumanB::HumanB(std::string name, Weapon weapon): name(name), weapon(weapon)
{
}

HumanB::HumanB(std::string name): name(name)
{
}

HumanB::~HumanB()
{
    std::cout << name << " is dead" << std::endl;
}

void HumanB::attack()
{
    if (weapon.getType() == "")
        std::cout << "has no weapon" << std::endl;
    else
        std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}