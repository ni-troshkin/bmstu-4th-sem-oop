#include "reader.h"

static err_t read_points(FILE *file, model_t &model);
static err_t read_links(FILE *file, model_t &model);
static err_t read_center(FILE *file, model_t &model);

static err_t check_read_link(link_t &link, FILE *file, const size_t links_count);


err_t scan_model(FILE *file, model_t &model)
{
    if (!file)
        return NULL_PTR_ERR;

    err_t err = read_points(file, model);
    if (err)
        return err;

    err = read_links(file, model);
    if (err)
        return err;

    err = read_center(file, model);
    return err;
}




static err_t read_points(FILE *file, model_t &model)
{
    if (!file)
        return NULL_PTR_ERR;

    if (fscanf(file, "%zu", &model.points_count) != 1)
        return READ_ERR;

    model.points = (point_t *)malloc(model.points_count * sizeof(point_t));
    if (!model.points)
        return ALLOC_ERR;

    err_t err = OK;
    for (size_t i = 0; i < model.points_count && !err; i++)
        if (fscanf(file, "%lf%lf%lf", &(model.points[i].x),
                       &(model.points[i].y), &(model.points[i].z)) != 3)
            err = READ_ERR;

    return err;
}

static err_t read_links(FILE *file, model_t &model)
{
    if (!file)
        return NULL_PTR_ERR;

    if (fscanf(file, "%zu", &model.links_count) != 1)
        return READ_ERR;

    model.links = (link_t *)malloc(model.links_count * sizeof(link_t));
    if (!model.links)
        return ALLOC_ERR;

    err_t err = OK;
    for (size_t i = 0; i < model.links_count && !err; i++)
        err = check_read_link(model.links[i], file, model.links_count);

    return err;
}

static err_t read_center(FILE *file, model_t &model)
{
    if (!file)
        return NULL_PTR_ERR;

    if (fscanf(file, "%lf%lf%lf",
               &model.center.x, &model.center.y, &model.center.z) != 3)
        return READ_ERR;

    return OK;
}




static err_t check_read_link(link_t &link, FILE *file, const size_t links_count)
{
    if (!file)
        return NULL_PTR_ERR;

    if (fscanf(file, "%zu%zu", &link.from, &link.to) != 2)
        return READ_ERR;

    if (link.from == link.to)
        return SELF_LINK;

    if (link.from >= links_count || link.to >= links_count)
        return POINT_NOT_EXIST;

    return OK;
}
