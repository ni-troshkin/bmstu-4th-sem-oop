#include <stdio.h>
#include <stdlib.h>

#include "writer.h"
#include "pointio.h"
#include "linkio.h"

static err_t write_points(FILE *file, const model_t &model);
static err_t write_links(FILE *file, const model_t &model);
static err_t write_center(FILE *file, const model_t &model);

err_t writer(FILE *file, const model_t &model)
{
    if (!file)
        return NULL_PTR_ERR;

    if (!model.points)
        return EMPTY_MODEL;

    err_t err = write_points(file, model);
    if (err)
        return err;

    err = write_links(file, model);
    if (err)
        return err;

    err = write_center(file, model);
    return err;
}

static err_t write_points(FILE *file, const model_t &model)
{
    if (!file)
        return NULL_PTR_ERR;

    if (!model.points)
        return EMPTY_MODEL;

    fprintf(file, "%zu\n", model.points_count);
    for (size_t i = 0; i < model.points_count; i++)
        write_point(file, model.points[i]);

    return OK;
}

static err_t write_links(FILE *file, const model_t &model)
{
    if (!file)
        return NULL_PTR_ERR;

    if (!model.links)
        return EMPTY_MODEL;

    fprintf(file, "%zu\n", model.links_count);
    for (size_t i = 0; i < model.links_count; i++)
        write_link(file, model.links[i]);

    return OK;
}

static err_t write_center(FILE *file, const model_t &model)
{
    if (!file)
        return NULL_PTR_ERR;

    if (!model.points)
        return EMPTY_MODEL;

    write_point(file, model.center);

    return OK;
}
