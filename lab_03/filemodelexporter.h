#ifndef FILEMODELEXPORTER_H
#define FILEMODELEXPORTER_H

#include "basemodelexporter.h"

class FileModelExporter: public BaseModelExporter
{
public:
    FileModelExporter();
    explicit FileModelExporter(std::shared_ptr<std::ofstream> output);
    virtual ~FileModelExporter() override = default;

    virtual void open(std::string filename) override;
    virtual void close() override;
    virtual void save(std::shared_ptr<Object> object) override;

private:
    std::shared_ptr<std::ofstream> file;
};

#endif // FILEMODELEXPORTER_H
