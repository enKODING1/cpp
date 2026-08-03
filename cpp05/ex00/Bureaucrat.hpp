#include <iostream>

class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
        void checkGrade(int grade);
    
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(std::string name, int grade);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName();
        int getGrade();
        void increaseGrade();
        void decreaseGrade();

        class GradeTooHighException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw();
        };
};
