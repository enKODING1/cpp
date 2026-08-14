#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : _name("foobar"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    checkGrade(_gradeToSign, _gradeToExecute);
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &other): _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    checkGrade(_gradeToSign, _gradeToExecute);
    std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    checkGrade(_gradeToSign, _gradeToExecute);
    std::cout << "Form constructor for the name " << name << " called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    std::cout << "Form assignment constructor called" << std::endl;
    if(this != &other)
           _isSigned = other._isSigned;

    return *this;
}

Form::~Form()
{
    std::cout << "Form deconstructor for " << _name << " called" << std::endl;
}

std::string Form::getName() const
{
    return _name;
}
bool Form::getIsSigned() const
{
    return _isSigned;
}
int Form::getGradeToSign() const
{
    return _gradeToSign;
}
int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
    int bGrade = b.getGrade();
    if(bGrade <= _gradeToSign) 
        _isSigned = true;
    else 
        throw Form::GradeTooLowException();
}

void Form::checkGrade(int gradeToSign, int gradeToExecute) const
{
    if(gradeToSign < 1 || gradeToExecute < 1)  
        throw Form::GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150) 
        throw Form::GradeTooLowException();
}

const char * Form::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

std::ostream& operator<<(std::ostream &os, const Form &f)
{
    return os << f.getName() << ", " << f.getIsSigned() << ", " << f.getGradeToSign() << ", " << f.getGradeToExecute();
}