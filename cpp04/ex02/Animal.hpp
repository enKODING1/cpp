#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
    std::string _type;

public:
    Animal();
    Animal(const std::string type);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();

    virtual void makeSound() const = 0;
    virtual std::string getType() const = 0;
    virtual void setType(const std::string type) = 0;
};

#endif