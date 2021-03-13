#ifndef ROTATION_H
#define ROTATION_H

#include "model.h"

double radians(const double deg);
err_t move_point(point_t &point, const double dx,
                 const double dy, const double dz);

err_t scale_point(point_t &point, const point_t &center,
                  const double kx, const double ky, const double kz);

err_t move_to_zero(model_t &model);
err_t rotate_x(model_t &model, const double thx);
err_t rotate_y(model_t &model, const double thy);
err_t rotate_z(model_t &model, const double thz);
err_t move_from_zero(model_t &model);

#endif // ROTATION_H
