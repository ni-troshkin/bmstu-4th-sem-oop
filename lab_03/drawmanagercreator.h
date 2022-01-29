#ifndef DRAWMANAGERCREATOR_H
#define DRAWMANAGERCREATOR_H

#include "drawmanager.h"

class DrawManagerCreator
{
public:
    std::shared_ptr<DrawManager> getManager();
private:
    std::shared_ptr<DrawManager> createManager();
    std::shared_ptr<DrawManager> manager;
};

#endif // DRAWMANAGERCREATOR_H
