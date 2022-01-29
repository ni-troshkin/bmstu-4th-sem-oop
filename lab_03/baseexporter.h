#ifndef BASEEXPORTER_H
#define BASEEXPORTER_H

#include <string>
#include <memory>
#include "object.h"

class BaseExporter
{
public:
    BaseExporter() = default;
    virtual ~BaseExporter() = default;

    virtual void open(std::string filename) = 0;
    virtual void save(std::shared_ptr<Object> object) = 0;
    virtual void close() = 0;
};


#endif // BASEEXPORTER_H
