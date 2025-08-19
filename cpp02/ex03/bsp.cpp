#include "Point.hpp"
#include "Fixed.hpp"

static Fixed vector_product(Point const src, Point const dest, Point const point)
{
    Fixed sd_x = dest.getX() - src.getX();
    Fixed sd_y = dest.getY() - src.getY();

    Fixed sp_x = point.getX() - src.getX();
    Fixed sp_y = point.getY() - src.getY();

    return sd_x * sp_y - sd_y * sp_x;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed cross1;
    Fixed cross2;
    Fixed cross3;

    cross1 = vector_product(a, b, point);
    cross2 = vector_product(b, c, point);
    cross3 = vector_product(c, a, point);

    if (cross1 > 0 && cross2 > 0 && cross3 > 0)
        return true;
    if (cross1 < 0 && cross2 < 0 && cross3 < 0)
        return true;
    return false;
}
