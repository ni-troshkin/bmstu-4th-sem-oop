#ifndef CAMERADIRECTOR_H
#define CAMERADIRECTOR_H

#include "basedirector.h"
#include "camerabuilder.h"
#include "basecameraloader.h"

class CameraDirector: public BaseDirector
{
public:
    explicit CameraDirector();
    CameraDirector(std::shared_ptr<BaseCameraLoader> loader, std::shared_ptr<CameraBuilder> builder);
    ~CameraDirector() = default;

    virtual std::shared_ptr<Object> build(std::string source) override;

private:
    std::shared_ptr<BaseCameraLoader> loader;
    std::shared_ptr<CameraBuilder> builder;
};

#endif // CAMERADIRECTOR_H
