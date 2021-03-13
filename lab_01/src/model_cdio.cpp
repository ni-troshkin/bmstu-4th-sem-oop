#include <stdio.h>
#include <stdlib.h>

#include "reader.h"
#include "writer.h"
#include "model_cdio.h"

static err_t zero_members(model_t &model);
static err_t free_model(model_t &model);


model_t init_model(void)
{
    model_t model;

    zero_members(model);

    return model;
}

err_t delete_model(model_t &model)
{
    free_model(model);

    return OK;
}

err_t read_model(const char *filename, model_t &model)
{
    if (!filename)
        return NULL_PTR_ERR;

    FILE *file = fopen(filename, "r");
    if (!file)
        return FILE_NOT_FOUND;

    free_model(model);
    zero_members(model);

    err_t err = scan_model(file, model);

    if (err)
    {
        free_model(model);
        zero_members(model);
    }

    fclose(file);

    return err;
}

err_t write_model(const char *filename, model_t &model)
{
    if (!filename)
        return NULL_PTR_ERR;

    FILE *file = fopen(filename, "w");
    if (!file)
        return INVALID_FILENAME;

    err_t err = output_model(file, model);

    fclose(file);
    return err;
}



static err_t zero_members(model_t &model)
{
    model.links = nullptr;
    model.points = nullptr;
    model.center.x = model.center.y = model.center.z = 0.0;
    model.links_count = model.points_count = 0;
    model.error = OK;

    return OK;
}

static err_t free_model(model_t &model)
{
    free(model.points);
    free(model.links);
    return OK;
}
