#include <stdlib.h>
#include "cleaner.h"

err_t zero_members(model_t &model)
{
    model.links = nullptr;
    model.points = nullptr;
    model.center.x = model.center.y = model.center.z = 0.0;
    model.links_count = model.points_count = 0;
    model.error = OK;

    return OK;
}

err_t free_model(model_t &model)
{
    free(model.points);
    free(model.links);
    return OK;
}
