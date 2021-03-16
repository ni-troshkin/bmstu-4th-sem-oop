#include <math.h>
#include <stdlib.h>

#include "transform.h"
#include "rotation.h"
#include "movescale.h"

#define EPS 1e-7

err_t move(model_t &model, const trans_args_t &args)
{
    if (!model.points)
        return EMPTY_MODEL;

    for (size_t i = 0; i < model.points_count; i++)
        move_point(model.points[i], args);

    move_point(model.center, args);

    return OK;
}

err_t scale(model_t &model, const trans_args_t &args)
{
    if (!model.points)
        return EMPTY_MODEL;

    err_t error = OK;

    for (size_t i = 0; i < model.points_count && !error; i++)
        error = scale_point(model.points[i], model.center, args);

    return error;
}

err_t rotate(model_t &model, const trans_args_t &args)
{
    if (!model.points)
        return EMPTY_MODEL;

    move_center_to_zero(model);
    rotate_x(model, radians(args.x));
    rotate_y(model, radians(args.y));
    rotate_z(model, radians(args.z));
    move_center_from_zero(model);

    return OK;
}
