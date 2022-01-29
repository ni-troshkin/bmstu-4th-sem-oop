#ifndef CAMERA_H
#define CAMERA_H

#include "object.h"

class Camera: public InvisibleObject
{
public:
    Camera() = default;
    Camera(const Point &pos);
    virtual ~Camera() override = default;

    virtual bool isComposite() override;

    virtual void transform(const Point &move, const Point &scale, const Point &rotate) override;
    virtual void accept(std::shared_ptr<BaseVisitor> visitor) override;

    void setPosition(const Point &point);
    Point &getPosition();

private:
    Point position;
};

#endif // CAMERA_H
