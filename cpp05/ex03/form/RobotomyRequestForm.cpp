#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"
#include "../Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45), _target("wall-e")
{
    std::cout << "\033[32m" << "RobotomyRequestForm default constructor called" << "\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
    std::cout << "\033[32m" << "RobotomyRequestForm copy constructor called" << "\033[0m" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "\033[32m" << "RobotomyRequestForm assignment constructor called" << "\033[0m" << std::endl;
    if (this != &other)
        _target = other._target;

    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "\033[33m" << "RobotomyRequestForm deconstructor for " << _target << " called" << "\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequest", 72, 45), _target(target)
{
    std::cout << "\033[32m" << "RobotomyRequestForm constructor for the name " << _target << " called" << "\033[0m" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    checkExecute(executor);
    std::srand(std::time(NULL));
    int roll = std::rand() % 2;

    if (roll == 1)
        std::cout << _target << " has been robotomized" << std::endl;
    if (roll == 0)
        std::cout << _target << " robotomy failed" << std::endl;
}