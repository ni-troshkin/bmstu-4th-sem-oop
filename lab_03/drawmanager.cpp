#include "drawmanager.h"
#include <iostream>

DrawManager::DrawManager()
{

}
void DrawManager::setDrawer(std::shared_ptr<BaseDrawer> drawer) {
    this->drawer = std::move(drawer);
}

void DrawManager::setCamera(std::shared_ptr<Camera> camera) {
    this->camera = std::move(camera);
}

Point DrawManager::proection(const Point &point) {
    Point new_point(point);
    Point cam_position(camera->getPosition());
    std::cout << point.get_x() << " " << point.get_y() << std::endl;
    std::cout << cam_position.get_x() << " " << cam_position.get_y() << std::endl;
    new_point.set_x(new_point.get_x() + cam_position.get_x());
    new_point.set_y(new_point.get_y() + cam_position.get_y());

    return new_point;
}
