#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "model.h"

err_t move(model_t &model, double dx, double dy, double dz);
err_t scale(model_t &model, double kx, double ky, double kz);
err_t rotate(model_t &model, double thx, double thy, double thz);

#endif // TRANSFORM_H
