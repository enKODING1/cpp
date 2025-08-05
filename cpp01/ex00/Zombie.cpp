#include "Zombie.hpp"

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name): name(name)
{
    std::cout << "created zombie " << name << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name  << " is dead" << std::endl;
}