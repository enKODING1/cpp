#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name): name(name)
{
    std::cout << "created zombie " << name << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name  << " is dead" << std::endl;
}