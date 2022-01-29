#ifndef FILECAMERAEXPORTER_H
#define FILECAMERAEXPORTER_H

#include "basecameraexporter.h"

class FileCameraExporter: public BaseCameraExporter
{
public:
    FileCameraExporter();
    explicit FileCameraExporter(std::shared_ptr<std::ofstream> output);
    virtual ~FileCameraExporter() override = default;

    virtual void open(std::string filename) override;
    virtual void close() override;
    virtual void save(std::shared_ptr<Object> object) override;

private:
    std::shared_ptr<std::ofstream> file;
};

#endif // FILECAMERAEXPORTER_H
