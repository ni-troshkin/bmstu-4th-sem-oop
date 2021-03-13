#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>
#include "model.h"

err_t scan_model(FILE *file, model_t &model);

#endif // READER_H
