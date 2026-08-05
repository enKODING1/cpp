#include "ShrubberyCreationForm.hpp"
#include "../Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("PresidentialPardon", 25, 5), _target("wall-e")
{
    std::cout << "ShrubberyCreationFormdefault constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationFormcopy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationFormassignment constructor called" << std::endl;
    if (this != &other)
        _target = other._target;

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationFormdeconstructor for " << _target << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("RobotomyRequest", 25, 5), _target(target)
{
    std::cout << "ShrubberyCreationFormconstructor for the name " << _target << " called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    bool isValid = getIsSigned() && (executor.getGrade() <= getGradeToExecute());
    if (!isValid)
        throw AForm::GradeTooLowException();
    // sign되어있지 않을 때를 별도 처리하는 예외를 만드는게 나을까
}