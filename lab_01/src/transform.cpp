#include <math.h>
#include <stdlib.h>

#include "transform.h"
#include "rotation.h"

#define EPS 1e-7

err_t move(model_t &model, const double dx,
          const double dy, const double dz)
{
    if (!model.points)
        return EMPTY_MODEL;

    for (size_t i = 0; i < model.points_count; i++)
        move_point(model.points[i], dx, dy, dz);

    move_point(model.center, dx, dy, dz);

    return OK;
}

err_t scale(model_t &model, const double kx,
           const double ky, const double kz)
{
    if (!model.points)
        return EMPTY_MODEL;

    if (fabs(kx) < EPS || fabs(ky) < EPS || fabs(kz) < EPS)
        return ZERO_SCALE;

    for (size_t i = 0; i < model.points_count; i++)
        scale_point(model.points[i], model.center, kx, ky, kz);

    return OK;
}

err_t rotate(model_t &model, const double thx,
             const double thy, const double thz)
{
    if (!model.points)
        return EMPTY_MODEL;

    move_to_zero(model);
    rotate_x(model, radians(thx));
    rotate_y(model, radians(thy));
    rotate_z(model, radians(thz));
    move_from_zero(model);

    return OK;
}
