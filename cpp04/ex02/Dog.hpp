#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *_brain;

public:
    Dog();
    Dog(const std::string type);
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    virtual ~Dog();

    virtual void makeSound() const;
    virtual std::string getType() const;
    virtual void setType(const std::string type);
    Brain &getBrain() const;
    void setBrain(Brain brain);
};

#endif