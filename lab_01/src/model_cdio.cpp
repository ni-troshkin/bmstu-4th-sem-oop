#include <stdio.h>
#include <stdlib.h>

#include "model_cdio.h"
#include "model.h"

void delete_model(model_t &model)
{
    if (model.points)
    {
        free(model.points);
        model.points = NULL;
    }

    if (model.links)
    {
        free(model.links);
        model.links = NULL;
    }

    model.links_count = model.points_count = 0;
    model.center.x = model.center.y = model.center.z = 0;
}

static int read_points(FILE *file, model_t &model)
{
    fscanf(file, "%zu", &model.points_count);

    model.points = (point_t *)malloc(model.points_count * sizeof(point_t));
    if (!model.points)
        return ALLOC_ERR;

    for (size_t i = 0; i < model.points_count; i++)
    {
        fscanf(file, "%lf", &(model.points[i].x));
        fscanf(file, "%lf", &(model.points[i].y));
        fscanf(file, "%lf", &(model.points[i].z));
    }

    return OK;
}

static int read_links(FILE *file, model_t &model)
{
    fscanf(file, "%zu", &model.links_count);

    model.links = (link_t *)malloc(model.links_count * sizeof(link_t));
    if (!model.links)
        return ALLOC_ERR;

    for (size_t i = 0; i < model.links_count; i++)
    {
        fscanf(file, "%zu", &(model.links[i].from));
        fscanf(file, "%zu", &(model.links[i].to));
    }

    return OK;
}

static void read_center(FILE *file, model_t &model)
{
    fscanf(file, "%lf", &model.center.x);
    fscanf(file, "%lf", &model.center.y);
    fscanf(file, "%lf", &model.center.z);
}

int read_model(const char *filename, model_t &model)
{
    FILE *file = fopen(filename, "r");
    if (!file)
        return FILE_NOT_FOUND;

    if (model.links || model.points)
        delete_model(model);

    int rc = read_points(file, model);
    if (rc)
        return rc;

    rc = read_links(file, model);
    if (rc)
    {
        free(model.points);
        return rc;
    }

    read_center(file, model);

    fclose(file);
    return OK;
}

static void write_points(FILE *file, model_t &model)
{
    fprintf(file, "%zu\n", model.points_count);
    for (size_t i = 0; i < model.points_count; i++)
        fprintf(file, "%.2lf %.2lf %.2lf\n",
            model.points[i].x, model.points[i].y, model.points[i].z);
}

static void write_links(FILE *file, model_t &model)
{
    fprintf(file, "%zu\n", model.links_count);
    for (size_t i = 0; i < model.links_count; i++)
        fprintf(file, "%zu %zu\n",
            model.links[i].from, model.links[i].to);
}

static void write_center(FILE *file, model_t &model)
{
    fprintf(file, "%.2lf %.2lf %.2lf", \
            model.center.x, model.center.y, model.center.z);
}

void write_model(const char *filename, model_t &model)
{
    FILE *file = fopen(filename, "w");

    if (!file)
        return;

    write_points(file, model);
    write_links(file, model);
    write_center(file, model);

    fclose(file);
}
