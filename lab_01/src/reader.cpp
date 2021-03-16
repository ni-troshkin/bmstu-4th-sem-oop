#include "reader.h"
#include "pointio.h"
#include "linkio.h"

static err_t read_points(model_t &model, FILE *file);
static err_t read_links(model_t &model, FILE *file);
static err_t read_center(model_t &model, FILE *file);

err_t reader(model_t &model, FILE *file)
{
    if (!file)
        return NULL_PTR_ERR;

    err_t err = read_points(model, file);
    if (err)
        return err;

    err = read_links(model, file);
    if (err)
        return err;

    err = read_center(model, file);
    return err;
}

static err_t read_points(model_t &model, FILE *file)
{
    if (!file)
        return NULL_PTR_ERR;

    if (fscanf(file, "%zu", &model.points_count) != 1)
        return READ_ERR;

    if (!model.points_count)
        return EMPTY_MODEL;

    model.points = (point_t *)malloc(model.points_count * sizeof(point_t));
    if (!model.points)
        return ALLOC_ERR;

    err_t err = OK;
    for (size_t i = 0; i < model.points_count && !err; i++)
        err = read_point(model.points[i], file);

    return err;
}

static err_t read_links(model_t &model, FILE *file)
{
    if (!file)
        return NULL_PTR_ERR;

    if (fscanf(file, "%zu", &model.links_count) != 1)
        return READ_ERR;

    if (!model.links_count)
        return EMPTY_MODEL;

    model.links = (link_t *)malloc(model.links_count * sizeof(link_t));
    if (!model.links)
        return ALLOC_ERR;

    err_t err = OK;
    for (size_t i = 0; i < model.links_count && !err; i++)
        err = read_link(model.links[i], file, model.links_count);

    return err;
}

static err_t read_center(model_t &model, FILE *file)
{
    if (!file)
        return NULL_PTR_ERR;

    err_t err = read_point(model.center, file);

    return err;
}
