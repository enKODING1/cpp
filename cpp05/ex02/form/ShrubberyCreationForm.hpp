#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "./interface/AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);

    virtual void execute(Bureaucrat const &executor) const;
};

#endif
