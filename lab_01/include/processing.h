#ifndef PROCESSING_H
#define PROCESSING_H

#include "model.h"

typedef enum
{
    EXIT,
    LOAD,
    SAVE,
    MOVE,
    SCALE,
    ROTATE
} action_t;

typedef struct
{
    action_t action;
    double x, y, z;
    const char *name;
} args_t;

model_t &process(const args_t &args);

#endif // PROCESSING_H
