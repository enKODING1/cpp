#include "PresidentialPardonForm.hpp"
#include "../Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5), _target("ford")
{
    std::cout << "\033[32m" << "PresidentialPardonForm default constructor called" << "\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
    std::cout << "\033[32m" << "PresidentialPardonForm copy constructor called" << "\033[0m" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "\033[32m" << "PresidentialPardonForm assignment constructor called" << "\033[0m" << std::endl;
    if (this != &other)
        _target = other._target;

    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "\033[33m" << "PresidentialPardonForm deconstructor for " << _target << " called" << "\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardon", 25, 5), _target(target)
{
    std::cout << "\033[32m" << "PresidentialPardonForm constructor for the name " << _target << " called" << "\033[0m" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    checkExecute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}