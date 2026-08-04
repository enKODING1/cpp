#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    try 
    {
        Bureaucrat b = Bureaucrat("skang", 150);
        std::cout << b << std::endl; 
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
