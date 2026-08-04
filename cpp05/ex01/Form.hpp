#include <iostream>

class Bureaucrat;

class Form{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign; 
        const int _gradeToExecute;
        void checkGrade(int gradeToSign, int gradeToExecute);
    public:
        Form();
        Form(const Form &other);
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form &operator=(const Form &other);
        ~Form();

        std::string getName();
        bool getIsSigned();
        int getGradeToSign();
        int getGradeToExecute();
        void beSigned(Bureaucrat &b);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw();
        };
};

std::ostream& operator<<(std::ostream &os, Form &f);