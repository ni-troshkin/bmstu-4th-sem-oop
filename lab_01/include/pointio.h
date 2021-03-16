#ifndef POINTIO_H
#define POINTIO_H

#include <stdio.h>
#include <stdlib.h>
#include "model.h"

err_t read_point(point_t &point, FILE *file);
err_t write_point(FILE *file, const point_t &point);

#endif // POINTIO_H
