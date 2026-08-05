#include "Bureaucrat.hpp"
#include "./form/RobotomyRequestForm.hpp"
#include "./form/PresidentialPardonForm.hpp"
#include "./form/ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Bureaucrat b = Bureaucrat("skang", 100);
        RobotomyRequestForm r = RobotomyRequestForm("skang");

        r.execute(b);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
