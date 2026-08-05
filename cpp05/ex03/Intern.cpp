#include "Intern.hpp"

Intern::Intern() {
  std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
  (void)other;
  std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
  std::cout << "Intern assignment constructor called" << std::endl;
  (void)other;
  return *this;
}

AForm *Intern::createShrubbery(std::string target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
  AForm *(Intern::*createForms[3])(std::string) = {&Intern::createShrubbery,
                                                   &Intern::createRobotomy,
                                                   &Intern::createPresidential};

  std::string formNames[3] = {"shrubbery creation", "robotomy request",
                              "presidential pardon"};

  for (int i = 0; i < 3; ++i) {
    if (formName == formNames[i])
      return (this->*createForms[i])(target);
  }

  throw std::runtime_error("Invalid form name");
  return NULL;
}

Intern::~Intern() { std::cout << "Intern deconstructor called" << std::endl; }