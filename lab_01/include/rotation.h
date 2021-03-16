#ifndef ROTATION_H
#define ROTATION_H

#include "model.h"
#include "args.h"

#define PI 3.14

double radians(const double deg);
err_t rotate_x(model_t &model, const double thx);
err_t rotate_y(model_t &model, const double thy);
err_t rotate_z(model_t &model, const double thz);

#endif // ROTATION_H
