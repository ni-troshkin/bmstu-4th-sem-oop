#include <math.h>

#include "transform.h"
#include "model.h"

#define PI 3.14

static double radians(const double deg)
{
    return deg * PI / 180.0;
}

void move(model_t &model, const double dx,
          const double dy, const double dz)
{
    for (size_t i = 0; i < model.points_count; i++)
    {
        model.points[i].x += dx;
        model.points[i].y += dy;
        model.points[i].z += dz;
    }
    model.center.x += dx;
    model.center.y += dy;
    model.center.z += dz;
}

void scale(model_t &model, const double kx,
           const double ky, const double kz)
{
    for (size_t i = 0; i < model.points_count; i++)
    {
        model.points[i].x = kx * model.points[i].x + model.center.x * (1 - kx);
        model.points[i].y = ky * model.points[i].y + model.center.y * (1 - ky);
        model.points[i].z = kz * model.points[i].z + model.center.z * (1 - kz);
    }
}

static void rotate_x(model_t &model, const double thx)
{
    for (size_t i = 0; i < model.points_count; i++)
    {
        double buf = model.points[i].y * cos(thx) + model.points[i].z * sin(thx)\
                + model.center.y * (1 - cos(thx)) - model.center.z * sin(thx);

        model.points[i].z = model.points[i].z * cos(thx) - model.points[i].y * sin(thx)\
                + model.center.z * (1 - cos(thx)) + model.center.y * sin(thx);

        model.points[i].y = buf;
    }
}

static void rotate_y(model_t &model, const double thy)
{
    for (size_t i = 0; i < model.points_count; i++)
    {
        double buf = model.points[i].z * cos(thy) + model.points[i].x * sin(thy)\
                + model.center.z * (1 - cos(thy)) - model.center.x * sin(thy);

        model.points[i].x = model.points[i].x * cos(thy) - model.points[i].z * sin(thy)\
                + model.center.x * (1 - cos(thy)) + model.center.z * sin(thy);

        model.points[i].z = buf;
    }
}

static void rotate_z(model_t &model, const double thz)
{
    for (size_t i = 0; i < model.points_count; i++)
    {
        double buf = model.points[i].x * cos(thz) + model.points[i].y * sin(thz)\
                + model.center.x * (1 - cos(thz)) - model.center.y * sin(thz);

        model.points[i].y = model.points[i].y * cos(thz) - model.points[i].x * sin(thz)\
                + model.center.y * (1 - cos(thz)) + model.center.x * sin(thz);

        model.points[i].x = buf;
    }
}

void rotate(model_t &model, const double thx, const double thy, const double thz)
{
    rotate_x(model, radians(thx));
    rotate_y(model, radians(thy));
    rotate_z(model, radians(thz));
}
