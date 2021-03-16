#ifndef MODEL_CDIO_H
#define MODEL_CDIO_H

#include "model.h"

//#include "reader.h"
//#include "writer.h"
//#include "cleaner.h"

model_t init_model(void);
err_t read_model(const char *filename, model_t &model);
err_t write_model(const char *filename, const model_t &model);
err_t delete_model(model_t &model);

#endif // MODEL_CDIO_H
