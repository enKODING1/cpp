#include "PresidentialPardonForm.hpp"
#include "../Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5), _target("ford")
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm assignment constructor called" << std::endl;
    if (this != &other)
        _target = other._target;

    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm deconstructor for " << _target << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardon", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm constructor for the name " << _target << " called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    bool isValid = getIsSigned() && (executor.getGrade() <= getGradeToExecute());
    if (!isValid)
        throw AForm::GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    // sign되어있지 않을 때를 별도 처리하는 예외를 만드는게 나을까
}