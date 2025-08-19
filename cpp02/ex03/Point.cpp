#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
}

Point::Point(const Point &p) : _x(p.getX()), _y(p.getY())
{
}

Point &Point::operator=(const Point &p)
{
    (void)p;
    return *this;
}

Point::~Point()
{
}

const Fixed &Point::getX() const
{
    return _x;
}

const Fixed &Point::getY() const
{
    return _y;
}
