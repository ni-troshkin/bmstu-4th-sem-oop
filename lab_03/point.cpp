#include "point.h"
#include <cmath>

double to_radians(const double &angle)
{
    return angle * (M_PI / 180.0);
}

Point::Point(const double x, const double y, const double z)
    : x(x), y(y), z(z) {}

Point::Point(const Point &&point) noexcept
    : x(point.x), y(point.y), z(point.z)
{
    point.~Point();
}

Point &Point::operator=(Point &&point) noexcept
{
    set_x(point.x);
    set_y(point.y);
    set_z(point.z);
    point.~Point();

    return *this;
}

double Point::get_x() const
{
    return x;
}

double Point::get_y() const
{
    return y;
}

double Point::get_z() const
{
    return z;
}

void Point::set_x(double const &x)
{
    this->x = x;
}

void Point::set_y(double const &y)
{
    this->y = y;
}

void Point::set_z(double const &z)
{
    this->z = z;
}

Point Point::operator+(const Point &pt)
{
    Point point{*this};

    point.set_x(point.x + pt.x);
    point.set_y(point.y + pt.y);
    point.set_z(point.z + pt.z);

    return point;
}

Point Point::operator-(const Point &pt)
{
    Point point{*this};

    point.set_x(point.x - pt.x);
    point.set_y(point.y - pt.y);
    point.set_z(point.z - pt.z);

    return point;
}

void Point::move(const double dx, const double dy, const double dz)
{
    set_x(x + dx);
    set_y(y + dy);
    set_z(z + dz);
}

void Point::scale(const double kx, const double ky, const double kz)
{
    set_x(x * kx);
    set_y(y * ky);
    set_z(z * kz);
}

void Point::rotate(const double thx, const double thy, const double thz)
{
    rotate_x(thx);
    rotate_y(thy);
    rotate_z(thz);
}

void Point::rotate_x(const double deg)
{
    const double r_cos = cos(to_radians(deg));
    const double r_sin = sin(to_radians(deg));
    const double temp_y = y;

    set_y(y * r_cos + z * r_sin);
    set_z(-temp_y * r_sin + z * r_cos);
}

void Point::rotate_y(const double deg)
{
    const double r_cos = cos(to_radians(deg));
    const double r_sin = sin(to_radians(deg));
    const double temp_x = x;

    set_x(x * r_cos + z * r_sin);
    set_z(-temp_x * r_sin + z * r_cos);
}

void Point::rotate_z(const double deg)
{
    const double r_cos = cos(to_radians(deg));
    const double r_sin = sin(to_radians(deg));
    const double temp_x = x;

    set_x(x * r_cos + y * r_sin);
    set_y(-temp_x * r_sin + y * r_cos);
}

bool Point::operator==(const Point &point) const noexcept
{
    return (point.x == x) && (point.y == y) && (point.z == z);
}

bool Point::isEqual(const Point &point) const noexcept
{
    return *this == point;
}

bool Point::operator!=(const Point &point) const noexcept
{
    return !(*this == point);
}

bool Point::isNotEqual(const Point &point) const noexcept
{
    return *this != point;
}

