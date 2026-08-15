#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Bureaucrat b = Bureaucrat("skang", 1);
        Form f = Form("form-1", 1, 2);

        b.signForm(f);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
