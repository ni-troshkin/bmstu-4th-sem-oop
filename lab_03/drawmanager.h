#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include <memory>
#include "basemanager.h"
#include "basedrawer.h"
#include "camera.h"
#include "visitor.h"

class DrawManager: public BaseManager
{
    friend void Visitor::visit(const Model &model);
public:
    DrawManager();
    DrawManager(const DrawManager &manager) = delete;
    DrawManager& operator=(const DrawManager &manager) = delete;

    ~DrawManager() = default;
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);
    void setCamera(std::shared_ptr<Camera> camera);
    void drawModel();

    Point proection(const Point &point);

private:
    std::shared_ptr<BaseDrawer> drawer;
    std::shared_ptr<Camera> camera;
};

#endif // DRAWMANAGER_H
