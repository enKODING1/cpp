#include "FragTrap.hpp"
#include <iostream>
#include <string>

int main(void)
{
    FragTrap attackBot("attackBot");
    FragTrap damageBot("damageBot");
    FragTrap repairBot("repairBot");

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
              << "---------highfive test---------" << std::endl;
    attackBot.highFivesGuys();
    damageBot.highFivesGuys();
    repairBot.highFivesGuys();

    std::cout << std::endl;
    return 0;
}