#ifndef MODEL_H
#define MODEL_H

#include <stdlib.h>

struct point_t
{
    double x;
    double y;
    double z;
};

struct link_t
{
    size_t from;
    size_t to;
};

enum err_t
{
    OK,
    FILE_NOT_FOUND,
    INVALID_FILENAME,
    ALLOC_ERR,
    NULL_PTR_ERR,
    READ_ERR,
    SELF_LINK,
    POINT_NOT_EXIST,
    INVALID_FUNC,
    EMPTY_MODEL,
    ZERO_SCALE
};

struct model_t
{
    point_t *points;
    size_t points_count;

    link_t *links;
    size_t links_count;

    point_t center;
    err_t error;
};

#endif // MODEL_H
