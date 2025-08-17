#include "Harl.hpp"

void Harl::debug()
{
   std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl; 
}

void Harl::info()
{
    std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
    std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*funcPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string complains[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i = 0;
    for (; i < 4; ++i)
    {  
        if (complains[i] == level)
            break;
    }

    switch (i)
    {
    case 0:
        (this->*(funcPtr[0]))();
    case 1:
        (this->*(funcPtr[1]))();
    case 2:
        (this->*(funcPtr[2]))();
    case 3:
        (this->*(funcPtr[3]))();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}