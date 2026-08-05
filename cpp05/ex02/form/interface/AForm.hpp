#include <iostream>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    void checkGrade(int gradeToSign, int gradeToExecute);

public:
    AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    ~AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &b);
    virtual void execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &os, AForm &f);