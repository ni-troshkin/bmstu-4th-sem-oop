#include <math.h>
#include <stdlib.h>

#include "rotation.h"

double radians(const double deg)
{
    return deg * PI / 180.0;
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
