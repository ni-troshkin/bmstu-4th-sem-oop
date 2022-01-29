#ifndef BASEMODELLOADER_H
#define BASEMODELLOADER_H

#include "baseloader.h"
#include "basebuilder.h"

class BaseModelLoader: public BaseLoader
{
public:
    virtual void open(std::string filename) = 0;
    virtual void close() = 0;

//    virtual std::shared_ptr<Object> load() = 0;

    virtual std::size_t loadIndex(std::size_t max_index) = 0;
    virtual double loadCoordinate() = 0;
    virtual std::size_t loadSize() = 0;
//    virtual void save(std::shared_ptr<Object>) = 0;
};

#endif // BASEMODELLOADER_H
