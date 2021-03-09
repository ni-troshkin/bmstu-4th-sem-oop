#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "model.h"

void move(model_t &model, double dx, double dy, double dz);
void scale(model_t &model, double kx, double ky, double kz);
void rotate(model_t &model, double thx, double thy, double thz);

#endif // TRANSFORM_H
