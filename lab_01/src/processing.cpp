#include "processing.h"
#include "model_cdio.h"
#include "transform.h"

model_t &process(const args_t &args)
{
    static model_t model = init_model();

    switch (args.action)
    {
        case EXIT: {
            model.error = delete_model(model);
            break;
        }
        case LOAD: {
            model.error = read_model(args.name, model);
            break;
        }
        case SAVE: {
            model.error = write_model(args.name, model);
            break;
        }
        case MOVE: {
            model.error = move(model, args.tr_args);
            break;
        }
        case SCALE: {
            model.error = scale(model, args.tr_args);
            break;
        }
        case ROTATE: {
            model.error = rotate(model, args.tr_args);
            break;
        }
        default: {
            model.error = INVALID_FUNC;
            break;
        }
    }

    return model;
}
