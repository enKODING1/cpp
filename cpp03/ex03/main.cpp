#include <iostream>
#include <string>
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap dia("dia");

    std::cout << "------" << std::endl;
    dia.whoAmI();
    std::cout << "------" << std::endl;
    dia.attack("bot");
    std::cout << "------" << std::endl;
    dia.takeDamage(10);
    return 0;
}