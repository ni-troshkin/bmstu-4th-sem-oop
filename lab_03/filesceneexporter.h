#ifndef FILESCENEEXPORTER_H
#define FILESCENEEXPORTER_H

#include "basesceneexporter.h"

class FileSceneExporter: public BaseSceneExporter
{
public:
    FileSceneExporter();
    explicit FileSceneExporter(std::shared_ptr<std::ofstream> output);
    virtual ~FileSceneExporter() override = default;

    virtual void open(std::string filename) override;
    virtual void close() override;
    virtual void save(std::shared_ptr<Object> object) override;

private:
    void saveModels(std::vector<std::shared_ptr<Object>> models);
    void saveCameras(std::vector<std::shared_ptr<Object>> cameras);
    std::shared_ptr<std::ofstream> file;
};

#endif // FILESCENEEXPORTER_H
