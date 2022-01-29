#ifndef CAMERABUILDER_H
#define CAMERABUILDER_H

#include <memory>
#include "basebuilder.h"
#include "camera.h"

class CameraBuilder//: public BaseBuilder
{
public:
    CameraBuilder() = default;
    ~CameraBuilder() = default;

//    virtual void build() override;
    void reset();
    std::shared_ptr<Camera> get();
    void buildPosition(double x, double y, double z);
private:
    std::shared_ptr<Camera> camera;
};

#endif // CAMERABUILDER_H
