#ifndef BASESCENEEXPORTER_H
#define BASESCENEEXPORTER_H

#include "baseexporter.h"

class BaseSceneExporter: public BaseExporter
{
public:
    virtual void open(std::string filename) = 0;
    virtual void close() = 0;

    virtual void save(std::shared_ptr<Object> object) = 0;
};

#endif // BASESCENEEXPORTER_H
