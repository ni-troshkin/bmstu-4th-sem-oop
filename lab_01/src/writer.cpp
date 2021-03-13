#include <stdio.h>
#include <stdlib.h>

#include "writer.h"

static err_t write_points(FILE *file, model_t &model);
static err_t write_links(FILE *file, model_t &model);
static err_t write_center(FILE *file, model_t &model);


err_t output_model(FILE *file, model_t &model)
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



static err_t write_points(FILE *file, model_t &model)
{
    if (!file)
        return NULL_PTR_ERR;

    if (!model.points)
        return EMPTY_MODEL;

    fprintf(file, "%zu\n", model.points_count);
    for (size_t i = 0; i < model.points_count; i++)
        fprintf(file, "%.2lf %.2lf %.2lf\n",
            model.points[i].x, model.points[i].y, model.points[i].z);

    return OK;
}

static err_t write_links(FILE *file, model_t &model)
{
    if (!file)
        return NULL_PTR_ERR;

    if (!model.links)
        return EMPTY_MODEL;

    fprintf(file, "%zu\n", model.links_count);
    for (size_t i = 0; i < model.links_count; i++)
        fprintf(file, "%zu %zu\n",
            model.links[i].from, model.links[i].to);

    return OK;
}

static err_t write_center(FILE *file, model_t &model)
{
    if (!file)
        return NULL_PTR_ERR;

    if (!model.points)
        return EMPTY_MODEL;

    fprintf(file, "%.2lf %.2lf %.2lf",
            model.center.x, model.center.y, model.center.z);
    return OK;
}
