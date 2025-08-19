#include "Fixed.hpp"

#include <cmath>

const int Fixed::_fractional_bits = 8;

Fixed::Fixed() : _fixed_point(0)
{
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
    // this->_fixed_point = other.getRawBits();
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->getRawBits() != other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        _fixed_point = other.getRawBits();
    }
    return *this;
}

/*arthmetic operator*/
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed res;
    res.setRawBits(this->getRawBits() + other.getRawBits());
    return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed res;
    res.setRawBits(this->getRawBits() - other.getRawBits());
    return res;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed res;
    res.setRawBits((this->getRawBits() * other.getRawBits()) >> this->_fractional_bits);
    return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
    this->_fixed_point++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_fixed_point++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->_fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_fixed_point--;
    return temp;
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
    if (n1 > n2)
        return n2;

    return n1;
}

const Fixed &Fixed::min(const Fixed &n1, const Fixed &n2)
{
    if (n1 > n2)
        return n2;
    return n1;
}

Fixed &Fixed::max(Fixed &n1, Fixed &n2)
{
    if (n1 < n2)
        return n2;
    return n1;
}

const Fixed &Fixed::max(const Fixed &n1, const Fixed &n2)
{
    if (n1 < n2)
        return n2;
    return n1;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int n)
{
    // int scale_factor = 1 << _fractional_bits;
    _fixed_point = n << _fractional_bits;
}

Fixed::Fixed(const float floating_point_n)
{
    int scale_factor = 1 << _fractional_bits;
    _fixed_point = roundf(floating_point_n * scale_factor);
}

int Fixed::getRawBits(void) const
{
    return _fixed_point;
}

void Fixed::setRawBits(int const raw)
{
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed_num)
{
    out << fixed_num.toFloat();
    return out;
}
