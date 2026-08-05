#include "Bureaucrat.hpp"
#include "./form/RobotomyRequestForm.hpp"
#include "./form/PresidentialPardonForm.hpp"
#include "./form/ShrubberyCreationForm.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Bureaucrat b = Bureaucrat("skang", 0);
        RobotomyRequestForm r = RobotomyRequestForm("skang1");
        PresidentialPardonForm p = PresidentialPardonForm("skang2");
        ShrubberyCreationForm s = ShrubberyCreationForm("skang3");

        // b.signForm(r);
        // b.signForm(p);
        b.signForm(s);

        // r.execute(b);
        // p.execute(b);
        b.executeForm(s);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
