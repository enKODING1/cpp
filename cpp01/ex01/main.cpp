#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    int nbZombie = 3;
    Zombie *horde = zombieHorde(nbZombie, "three idiots");

    for(int i = 0; i < nbZombie; ++i) 
        horde->announce();

    delete[] horde;
    return 0;
}