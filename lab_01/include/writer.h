#ifndef WRITER_H
#define WRITER_H

#include <stdio.h>
#include "model.h"

//#include "pointio.h"
//#include "linkio.h"

err_t writer(FILE *file, const model_t &model);

#endif // WRITER_H
