#include <stdio.h>
#include <stdlib.h>

#include "linkio.h"

err_t read_link(link_t &link, FILE *file, const size_t links_count)
{
    if (!file)
        return NULL_PTR_ERR;

    if (fscanf(file, "%zu%zu", &link.from, &link.to) != 2)
        return READ_ERR;

    if (link.from == link.to)
        return SELF_LINK;

    if (link.from >= links_count || link.to >= links_count)
        return POINT_NOT_EXIST;

    return OK;
}

err_t write_link(FILE *file, const link_t &link)
{
    if (!file)
        return NULL_PTR_ERR;

    fprintf(file, "%zu %zu\n", link.from, link.to);

    return OK;
}
