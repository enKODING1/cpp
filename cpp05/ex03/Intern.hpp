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

  AForm *createShrubbery(const std::string &target) const;
  AForm *createRobotomy(const std::string &target) const;
  AForm *createPresidential(const std::string &target) const;
  AForm *makeForm(const std::string &formName, const std::string &target) const;
};

#endif
