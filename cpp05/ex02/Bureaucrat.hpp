#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    void checkGrade(int grade) const;

public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;
    void increaseGrade();
    void decreaseGrade();
    void signForm(AForm &f) const;
    void executeForm(AForm const &form) const;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
