#ifndef INTERN_HPP
#define INTERN_HPP

#include "./form/interface/AForm.hpp"
#include "form/PresidentialPardonForm.hpp"
#include "form/RobotomyRequestForm.hpp"
#include "form/ShrubberyCreationForm.hpp"
#include <iostream>

class Intern {
private:
public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  AForm *createShrubbery(std::string target);
  AForm *createRobotomy(std::string target);
  AForm *createPresidential(std::string target);
  AForm *makeForm(std::string formName, std::string target);
};

#endif
