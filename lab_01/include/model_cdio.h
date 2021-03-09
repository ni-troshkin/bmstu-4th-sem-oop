#ifndef MODEL_CDIO_H
#define MODEL_CDIO_H

#include "model.h"

#define OK 0
#define FILE_NOT_FOUND -1
#define ALLOC_ERR -2

void delete_model(model_t &model);
void write_model(const char *filename, model_t &model);
int read_model(const char *filename, model_t &model);

#endif // MODEL_CDIO_H
