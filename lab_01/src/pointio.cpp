#include <stdio.h>
#include <stdlib.h>

#include "pointio.h"

err_t read_point(point_t &point, FILE *file)
{
    if (!file)
        return NULL_PTR_ERR;

    if (fscanf(file, "%lf%lf%lf", &point.x, &point.y, &point.z) != 3)
        return READ_ERR;

    return OK;
}

err_t write_point(FILE *file, const point_t &point)
{
    if (!file)
        return NULL_PTR_ERR;

    fprintf(file, "%.2lf %.2lf %.2lf\n", point.x, point.y, point.z);

    return OK;
}
