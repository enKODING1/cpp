#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    Bureaucrat b = Bureaucrat("skang", 3);
    Form f = Form("form-1", 2, 1);

    b.signForm(f);
    
    return 0;
}
