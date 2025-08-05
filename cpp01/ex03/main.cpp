#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"


int main()
{
{
Weapon club = Weapon("tank");
HumanA bob("Bob", club);
bob.attack();
club.setType("water");
bob.attack();
}
{
Weapon club = Weapon("knife");
HumanB jim("Jim");
jim.setWeapon(club);
jim.attack();
club.setType("fire");
jim.attack();
}
return 0;
}