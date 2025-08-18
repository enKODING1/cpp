#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractional_bits = 8;

Fixed::Fixed():_fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
    // this->_fixed_point = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        _fixed_point = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    // int scale_factor = 1 << _fractional_bits;
    _fixed_point = n << _fractional_bits;
    std::cout << "Integer constructor called" << std::endl;
}

Fixed::Fixed(const float floating_point_n)
{
    int scale_factor = 1 << _fractional_bits;
    _fixed_point = roundf(floating_point_n * scale_factor);
    std::cout << "Float constructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _fixed_point;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixed_point = raw;
}

float Fixed::toFloat(void) const
{
    return (float)_fixed_point / ((float)(1 << _fractional_bits));
}

int Fixed::toInt(void) const
{
    return (int)(_fixed_point >> _fractional_bits);
}


std::ostream& operator<<(std::ostream &out, const Fixed &fixed_num)
{
    out << fixed_num.toFloat();
    return out;
}
