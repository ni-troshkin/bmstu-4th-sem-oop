#ifndef BASECAMERAEXPORTER_H
#define BASECAMERAEXPORTER_H

#include <baseexporter.h>

class BaseCameraExporter: public BaseExporter
{
public:
    virtual void open(std::string filename) = 0;
    virtual void close() = 0;

    virtual void save(std::shared_ptr<Object> object) = 0;
};

#endif // BASECAMERAEXPORTER_H
