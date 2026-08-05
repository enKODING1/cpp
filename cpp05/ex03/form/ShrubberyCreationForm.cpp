#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "../Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), _target("wall-e")
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

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationFormconstructor for the name " << _target << " called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    bool isValid = getIsSigned() && (executor.getGrade() <= getGradeToExecute());
    if (!isValid)
        throw AForm::GradeTooLowException();
    std::string ascii_tree =
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
    // sign되어있지 않을 때를 별도 처리하는 예외를 만드는게 나을까
}