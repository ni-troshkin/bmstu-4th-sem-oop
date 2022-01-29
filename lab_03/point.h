#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point() = default;
    Point(const double x, const double y, const double z);

    Point(const Point &point) = default;
    Point &operator=(const Point &point) = default;

    Point(const Point &&point) noexcept;
    Point &operator=(Point &&point) noexcept;

    bool operator==(const Point &point) const noexcept;
    bool isEqual(const Point &point) const noexcept;

    bool operator!=(const Point &point) const noexcept;
    bool isNotEqual(const Point &point) const noexcept;

    ~Point() = default;

    double get_x() const;
    double get_y() const;
    double get_z() const;

    void set_x(double const &x);
    void set_y(double const &y);
    void set_z(double const &z);

    Point operator+(const Point &p);
    Point sum(const Point &p);

    Point operator-(const Point &p);
    Point diff(const Point &p);

    void move(const double dx, const double dy, const double dz);
    void scale(const double kx, const double ky, const double kz);
    void rotate(const double thx, const double thy, const double thz);

    void rotate_x(const double deg);
    void rotate_y(const double deg);
    void rotate_z(const double deg);

private:
    double x, y, z;
};

#endif // POINT_H
