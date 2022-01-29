#ifndef FILECAMERALOADER_H
#define FILECAMERALOADER_H

#include "basecameraloader.h"
#include "camerabuilder.h"

class FileCameraLoader: public BaseCameraLoader
{
public:
    FileCameraLoader();
    explicit FileCameraLoader(std::shared_ptr<std::ifstream> input);
    virtual ~FileCameraLoader() override = default;

//    virtual std::shared_ptr<Object> load() override;
    virtual void open(std::string filename) override;
    virtual void close() override;

    virtual std::size_t loadIndex(std::size_t max_index) override;
    virtual double loadCoordinate() override;
    virtual std::size_t loadSize() override;

//    virtual void save(std::shared_ptr<Object>) override;
private:
    std::shared_ptr<std::ifstream> file;
    std::shared_ptr<CameraBuilder> builder;
};

#endif // FILECAMERALOADER_H
