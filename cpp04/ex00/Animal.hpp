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

    virtual void makeSound() const;
    virtual std::string getType() const;
    virtual void setType(const std::string type);
};

class Dog : public Animal
{
private:
public:
    Dog();
    Dog(const std::string type);
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();

    void makeSound() const;
    std::string getType() const;
    void setType(const std::string type);
};

class Cat : public Animal
{
private:
public:
    Cat();
    Cat(const std::string type);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat();

    void makeSound() const;
    std::string getType() const;
    void setType(const std::string type);
};
#endif