#ifndef BASELOADER_H
#define BASELOADER_H

#include <string>
#include <memory>
#include "object.h"
#include "basebuilder.h"

class BaseLoader
{
public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void open(std::string filename) = 0;

    virtual std::size_t loadIndex(std::size_t max_index) = 0;
    virtual double loadCoordinate() = 0;
    virtual std::size_t loadSize() = 0;

    virtual void close() = 0;
};

#endif // BASELOADER_H
