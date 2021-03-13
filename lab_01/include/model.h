#ifndef MODEL_H
#define MODEL_H

#include <stdlib.h>

typedef struct
{
    double x;
    double y;
    double z;
} point_t;

typedef struct
{
    size_t from;
    size_t to;
} link_t;

typedef enum
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
} err_t;

typedef struct
{
    point_t *points;
    size_t points_count;

    link_t *links;
    size_t links_count;

    point_t center;
    err_t error;
} model_t;

#endif // MODEL_H
