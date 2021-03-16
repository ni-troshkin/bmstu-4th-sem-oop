#include <math.h>
#include <stdlib.h>

#include "movescale.h"

err_t move_point(point_t &point, const trans_args_t &args)
{
    point.x += args.x;
    point.y += args.y;
    point.z += args.z;

    return OK;
}

err_t scale_point(point_t &point, const point_t &center, const trans_args_t &args)
{
    if (fabs(args.x) < EPS || fabs(args.y) < EPS || fabs(args.z) < EPS)
        return ZERO_SCALE;

    point.x = args.x * point.x + center.x * (1 - args.x);
    point.y = args.y * point.y + center.y * (1 - args.y);
    point.z = args.z * point.z + center.z * (1 - args.z);

    return OK;
}

err_t move_center_to_zero(model_t &model)
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

err_t move_center_from_zero(model_t &model)
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
