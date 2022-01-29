#include "camerabuilder.h"
#include "camera.h"
#include "point.h"

void CameraBuilder::reset()
{
    camera = std::make_shared<Camera>();
}

void CameraBuilder::buildPosition(double x, double y, double z)
{
    Point pos(x, y, z);
    camera->setPosition(pos);
}

std::shared_ptr<Camera> CameraBuilder::get()
{
    return camera;
}
