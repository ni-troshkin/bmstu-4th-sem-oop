#ifndef BASEMODELEXPORTER_H
#define BASEMODELEXPORTER_H

#include "baseexporter.h"

class BaseModelExporter: public BaseExporter
{
public:
    virtual void open(std::string filename) = 0;
    virtual void close() = 0;

    virtual void save(std::shared_ptr<Object> object) = 0;
};

#endif // BASEMODELEXPORTER_H
