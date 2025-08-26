#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;

public:
    Cat();
    Cat(const std::string type);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    virtual ~Cat();

    virtual void makeSound() const;
    virtual std::string getType() const;
    virtual void setType(const std::string type);
    Brain &getBrain() const;
    void setBrain(Brain brain);
};

#endif