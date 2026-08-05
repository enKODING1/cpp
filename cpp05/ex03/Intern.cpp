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

Intern::~Intern() { std::cout << "Intern deconstructor called" << std::endl; }