#ifndef MODEL_H
#define MODEL_H

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

typedef struct
{
    point_t *points;
    size_t points_count;

    link_t *links;
    size_t links_count;

    point_t center;
} model_t;

#endif // MODEL_H
