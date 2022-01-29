#include "cameradirector.h"
#include "filecameraloader.h"

CameraDirector::CameraDirector()
{
    loader = std::shared_ptr<FileCameraLoader>(new FileCameraLoader());
}

CameraDirector::CameraDirector(std::shared_ptr<BaseCameraLoader> loader, std::shared_ptr<CameraBuilder> builder)
    : loader(std::move(loader)), builder(std::move(builder)) {}

std::shared_ptr<Object> CameraDirector::build(std::string source)
{
    loader->open(source);
    builder->reset();

    double x, y, z;
    x = loader->loadCoordinate();
    y = loader->loadCoordinate();
    z = loader->loadCoordinate();
    builder->buildPosition(x, y, z);

    std::shared_ptr<Object> camera = builder->get();
    loader->close();

    return camera;
}
