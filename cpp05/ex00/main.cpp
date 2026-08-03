#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    try 
    {
        Bureaucrat b = Bureaucrat("skang", 151);
        std::cout << b.getName() << std::endl;
        std::cout << b.getGrade() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
