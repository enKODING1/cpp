#include "Intern.hpp"

Intern::Intern() {
  std::cout << "\033[32m" << "Intern default constructor called" << "\033[0m" << std::endl;
}

Intern::Intern(const Intern &other) {
  (void)other;
  std::cout << "\033[32m" << "Intern copy constructor called" << "\033[0m" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
  std::cout << "\033[32m" << "Intern assignment constructor called" << "\033[0m" << std::endl;
  (void)other;
  return *this;
}

AForm *Intern::createShrubbery(const std::string &target) const {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target) const {
  return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target) const {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const {
  AForm *(Intern::*createForms[3])(const std::string &) const = {
      &Intern::createShrubbery, &Intern::createRobotomy,
      &Intern::createPresidential};

  const std::string formNames[3] = {"shrubbery creation", "robotomy request",
                                    "presidential pardon"};

  for (int i = 0; i < 3; ++i) {
    if (formName == formNames[i])
      return (this->*createForms[i])(target);
  }

  throw std::runtime_error("Invalid form name");
  return NULL;
}

Intern::~Intern() { std::cout << "\033[33m" << "Intern deconstructor called" << "\033[0m" << std::endl; }