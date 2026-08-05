#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "./interface/AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const  PresidentialPardonForm &other);
        ~PresidentialPardonForm();
        PresidentialPardonForm(std::string target);

        virtual void execute(Bureaucrat const & executor) const;
};

#endif
