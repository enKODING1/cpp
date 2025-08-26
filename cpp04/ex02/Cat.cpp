#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const std::string type) : Animal(type)
{
    std::cout << "Cat constructor for the type " << _type << " called" << std::endl;
    _brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat assignment constructor called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
        if (_brain != NULL)
            delete _brain;
        _brain = new Brain(*other._brain);
    }

    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat deconstructor for " << _type << " called" << std::endl;
    delete _brain;
}

void Cat::makeSound() const
{
    std::cout << "meow!! meow!!" << std::endl;
}

std::string Cat::getType() const
{
    return _type;
}

void Cat::setType(const std::string type)
{
    _type = type;
}

Brain &Cat::getBrain() const
{
    return *_brain;
}

void Cat::setBrain(Brain brain)
{
    *_brain = brain;
}