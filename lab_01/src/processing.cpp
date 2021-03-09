#include <stdlib.h>
#include <stdarg.h>

#include "processing.h"
#include "model_cdio.h"
#include "model.h"
#include "transform.h"

model_t& process(const action_t action, ...)
{
    static model_t model = {0};
    va_list args;
    va_start(args, action);

    switch (action)
    {
        case EXIT: {
            delete_model(model);
            break;
        }

        case LOAD: {
            const char *openname = va_arg(args, const char *);
            int rc = read_model(openname, model);
            if (rc)
                model.points = NULL;
            break;
        }
        case SAVE: {
            const char *savename = va_arg(args, const char *);
            write_model(savename, model);
            break;
        }
        case MOVE:
        case SCALE:
        case ROTATE: {
            double x = va_arg(args, double);
            double y = va_arg(args, double);
            double z = va_arg(args, double);
            if (action == MOVE)
                move(model, x, y, z);
            else if (action == SCALE)
                scale(model, x, y, z);
            else
                rotate(model, x, y, z);
            break;
        }
        default:
            break;
    }

    va_end(args);
    return model;
}
