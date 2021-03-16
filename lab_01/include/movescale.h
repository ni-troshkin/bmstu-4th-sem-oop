#ifndef MOVESCALE_H
#define MOVESCALE_H

#include "args.h"
#include "model.h"

#define EPS 1e-7

err_t move_point(point_t &point, const trans_args_t &args);
err_t scale_point(point_t &point, const point_t &center, const trans_args_t &args);
err_t move_center_to_zero(model_t &model);
err_t move_center_from_zero(model_t &model);

#endif // MOVESCALE_H
