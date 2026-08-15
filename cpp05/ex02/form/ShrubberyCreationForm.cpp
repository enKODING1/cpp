#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "../Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), _target("wall-e")
{
    std::cout << "\033[32m" << "ShrubberyCreationFormdefault constructor called" << "\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
    std::cout << "\033[32m" << "ShrubberyCreationFormcopy constructor called" << "\033[0m" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "\033[32m" << "ShrubberyCreationFormassignment constructor called" << "\033[0m" << std::endl;
    if (this != &other)
        _target = other._target;

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "\033[33m" << "ShrubberyCreationFormdeconstructor for " << _target << " called" << "\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{
    std::cout << "\033[32m" << "ShrubberyCreationFormconstructor for the name " << _target << " called" << "\033[0m" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    const std::string ascii_tree =
        "       &&& &&  & &&\n"
        "     && &\\/&\\|& ()|/ @, &&\n"
        "     &\\/(/&/&||/&/&/\\)&/&\\@\n"
        "   &() &&/&\\/&&&&&/(&&& ()__/\\\n"
        "  &&, &&&/&(&&& &)&/&&&/&\n"
        "   &&(&&&&/&&&&/&(&&|(&&/&&&\n"
        "    &&&&&&/|/&&/&/(/&&&&/&&&\n"
        "      &&/&& & &&/&/&(&&|/&&&\n"
        "        &&&&&(&//&/&&&(/&&&\n"
        "            &&(/&&|\n"
        "             ||||\n"
        "             ||||";

    std::string name = _target + "_shrubbery";
    std::ofstream file(name.c_str());
    file << ascii_tree << std::endl;
    file.close();
}