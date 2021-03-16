#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>
#include "model.h"

//#include "pointio.h"
//#include "linkio.h"

err_t reader(model_t &model, FILE *file);

#endif // READER_H
