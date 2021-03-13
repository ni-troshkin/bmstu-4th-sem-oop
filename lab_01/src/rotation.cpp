#include <math.h>
#include <stdlib.h>

#include "rotation.h"

#define PI 3.14
#define EPS 1e-7

double radians(const double deg)
{
    return deg * PI / 180.0;
}

err_t move_point(point_t &point, const double dx,
                 const double dy, const double dz)
{
    point.x += dx;
    point.y += dy;
    point.z += dz;

    return OK;
}

err_t scale_point(point_t &point, const point_t &center,
                  const double kx, const double ky, const double kz)
{
    if (fabs(kx) < EPS || fabs(ky) < EPS || fabs(kz) < EPS)
        return ZERO_SCALE;

    point.x = kx * point.x + center.x * (1 - kx);
    point.y = ky * point.y + center.y * (1 - ky);
    point.z = kz * point.z + center.z * (1 - kz);

    return OK;
}

err_t move_to_zero(model_t &model)
{
    if (!model.points)
        return NULL_PTR_ERR;

    for (size_t i = 0; i < model.points_count; i++)
    {
        model.points[i].x -= model.center.x;
        model.points[i].y -= model.center.y;
        model.points[i].z -= model.center.z;
    }

    return OK;
}

err_t rotate_x(model_t &model, const double thx)
{
    if (!model.points)
        return NULL_PTR_ERR;

    for (size_t i = 0; i < model.points_count; i++)
    {
        double buf = model.points[i].y * cos(thx) + model.points[i].z * sin(thx);;
        model.points[i].z = model.points[i].z * cos(thx) - model.points[i].y * sin(thx);
        model.points[i].y = buf;
    }

    return OK;
}

err_t rotate_y(model_t &model, const double thy)
{
    if (!model.points)
        return NULL_PTR_ERR;

    for (size_t i = 0; i < model.points_count; i++)
    {
        double buf = model.points[i].z * cos(thy) + model.points[i].x * sin(thy);;
        model.points[i].x = model.points[i].x * cos(thy) - model.points[i].z * sin(thy);
        model.points[i].z = buf;
    }

    return OK;
}

err_t rotate_z(model_t &model, const double thz)
{
    if (!model.points)
        return NULL_PTR_ERR;

    for (size_t i = 0; i < model.points_count; i++)
    {
        double buf = model.points[i].x * cos(thz) + model.points[i].y * sin(thz);;
        model.points[i].y = model.points[i].y * cos(thz) - model.points[i].x * sin(thz);
        model.points[i].x = buf;
    }

    return OK;
}

err_t move_from_zero(model_t &model)
{
    if (!model.points)
        return NULL_PTR_ERR;

    for (size_t i = 0; i < model.points_count; i++)
    {
        model.points[i].x += model.center.x;
        model.points[i].y += model.center.y;
        model.points[i].z += model.center.z;
    }

    return OK;
}
