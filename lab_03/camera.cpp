#include "camera.h"

Camera::Camera(const Point &pos)
    : position(pos) {}

bool Camera::isComposite()
{
    return false;
}

void Camera::transform(const Point &move, const Point &scale, const Point &rotate)
{
    position.set_x(position.get_x() + move.get_x());
    position.set_y(position.get_y() + move.get_y());
}

void Camera::accept(std::shared_ptr<BaseVisitor> visitor)
{
    visitor->visit(*this);
}

Point &Camera::getPosition()
{
    return position;
}

void Camera::setPosition(const Point &point)
{
    position = point;
}
