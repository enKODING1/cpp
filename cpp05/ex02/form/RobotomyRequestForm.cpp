#include "RobotomyRequestForm.hpp"
#include "../Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("PresidentialPardon", 25, 5), _target("wall-e")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm assignment constructor called" << std::endl;
    if (this != &other)
        _target = other._target;

    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm deconstructor for " << _target << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 25, 5), _target(target)
{
    std::cout << "RobotomyRequestForm constructor for the name " << _target << " called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    bool isValid = getIsSigned() && (executor.getGrade() <= getGradeToExecute());
    if (!isValid)
        throw AForm::GradeTooLowException();
    // sign되어있지 않을 때를 별도 처리하는 예외를 만드는게 나을까
}