#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main(void)
{
    ScavTrap attackBot("attackBot");
    ScavTrap damageBot("damageBot");
    ScavTrap repairBot("repairBot");

    /* attack test */
    std::cout << std::endl
              << "---------attack test---------" << std::endl;
    for (int i = 0; i < 11; ++i)
        attackBot.attack("pikachu");

    /* damage test */
    std::cout << std::endl
              << "---------damage test---------" << std::endl;
    for (int i = 0; i < 3; ++i)
        damageBot.takeDamage(5);

    /* repair test */
    std::cout << std::endl
              << "---------repair test---------" << std::endl;
    repairBot.takeDamage(2);
    for (int i = 0; i < 3; ++i)
        repairBot.beRepaired(5);

    std::cout << std::endl
              << "---------guarding gate test---------" << std::endl;
    attackBot.guardGate();
    attackBot.guardGate();
    attackBot.guardGate();
    std::cout << std::endl;
    return 0;
}