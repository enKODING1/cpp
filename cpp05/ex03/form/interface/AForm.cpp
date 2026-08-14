#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("untitled"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    checkGrade(_gradeToSign, _gradeToExecute);
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    checkGrade(_gradeToSign, _gradeToExecute);
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    checkGrade(_gradeToSign, _gradeToExecute);
    std::cout << "AForm constructor for the name " << name << " called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "AForm assignment constructor called" << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;

    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm deconstructor for " << _name << " called" << std::endl;
}

std::string AForm::getName() const
{
    return _name;
}
bool AForm::getIsSigned() const
{
    return _isSigned;
}
int AForm::getGradeToSign() const
{
    return _gradeToSign;
}
int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    int bGrade = b.getGrade();
    if (bGrade <= _gradeToSign)
        _isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::checkGrade(int gradeToSign, int gradeToExecute) const
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "grade is too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    return os << f.getName() << ", " << f.getIsSigned() << ", " << f.getGradeToSign() << ", " << f.getGradeToExecute();
}