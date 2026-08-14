#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "./interface/AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm&operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);

        virtual void execute(Bureaucrat const & executor) const;
};

#endif
