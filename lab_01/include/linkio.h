#ifndef LINKIO_H
#define LINKIO_H

#include <stdio.h>
#include <stdlib.h>

#include "model.h"

err_t read_link(link_t &link, FILE *file, const size_t links_count);
err_t write_link(FILE *file, const link_t &link);

#endif // LINKIO_H
