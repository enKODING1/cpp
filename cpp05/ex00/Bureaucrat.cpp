#include "Bureaucrat.hpp"



Bureaucrat::Bureaucrat() : _name("foobar"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
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

std::string Bureaucrat::getName()
{
    return _name;
}

int Bureaucrat::getGrade()
{
    return _grade;
}

void Bureaucrat::increaseGrade()
{
    /* 1~150의 범위를 벗어날 경우 에러 발생시키는 예외로직 추가하기 */
    int num = _grade - 1;

    if (num < 1)
    {
        std::cout << _name << ", bureaucrat grade too hight: " << _grade << "." << std::endl;
        return;
    }

    _grade--;
}

void Bureaucrat::decreaseGrade()
{
    int num = _grade + 1;

    if(num > 150)
    {
        std::cout << _name << ", bureaucrat grade too low: " << _grade << "." << std::endl;
        return;
    }

    _grade++;
}