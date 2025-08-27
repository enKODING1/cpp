#ifndef CURE_HPP
#define CURE_HPP

#include <string>

class Cure
{
private:
    std::string type;

public:
    Cure *Clone();
};

#endif