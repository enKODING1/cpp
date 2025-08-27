#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria *m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter &target) = 0;
};

class Character : public ICharacter
{
private:
    std::string _name;

public:
    Character();
    Character(const Character &other);
    Character(std::string name);
    Character &operator=(const Character &other);
    ~Character();
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};
#endif