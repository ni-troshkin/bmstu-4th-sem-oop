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

model_t &process(action_t action, ...);

#endif // PROCESSING_H
