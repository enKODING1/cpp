#include "Bureaucrat.hpp"



Bureaucrat::Bureaucrat() : _name("foobar"), _grade(150)
{
    checkGrade(_grade);
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
    checkGrade(_grade);
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    checkGrade(_grade);
   std::cout << "Bureaucrat constructor for the name " << name << " called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat assignment constructor called" << std::endl;
    if(this != &other)
        _grade = other._grade;

    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat deconstructor for " << _name << " called" << std::endl;
}

void Bureaucrat::checkGrade(int grade)
{
    if(grade < 1) throw Bureaucrat::GradeTooHighException();
    if(grade > 150) throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::increaseGrade()
{
    checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decreaseGrade()
{
    checkGrade(_grade + 1);
    _grade++;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b){
    return os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}