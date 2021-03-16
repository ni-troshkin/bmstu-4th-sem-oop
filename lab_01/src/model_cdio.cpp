#include <stdio.h>
#include <stdlib.h>

#include "reader.h"
#include "writer.h"
#include "cleaner.h"
#include "model_cdio.h"

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

    err_t err = reader(model, file);

    if (err)
    {
        free_model(model);
        zero_members(model);
    }

    fclose(file);

    return err;
}

err_t write_model(const char *filename, const model_t &model)
{
    if (!filename)
        return NULL_PTR_ERR;

    FILE *file = fopen(filename, "w");
    if (!file)
        return INVALID_FILENAME;

    err_t err = writer(file, model);

    fclose(file);
    return err;
}
