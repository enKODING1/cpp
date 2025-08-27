#ifndef ICE_HPP
#define ICE_HPP

#include <string>

class Ice
{
private:
    std::string type;

public:
    Ice *clone();
};

#endif