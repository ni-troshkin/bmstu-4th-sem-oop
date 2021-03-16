#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "model.h"
#include "args.h"

//#include "rotation.h"
//#include "movescale.h"

err_t move(model_t &model, const trans_args_t &args);
err_t scale(model_t &model, const trans_args_t &args);
err_t rotate(model_t &model, const trans_args_t &args);

#endif // TRANSFORM_H
