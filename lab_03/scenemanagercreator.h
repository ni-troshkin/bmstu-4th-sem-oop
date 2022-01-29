#ifndef SCENEMANAGERCREATOR_H
#define SCENEMANAGERCREATOR_H

#include "scenemanager.h"

class SceneManagerCreator
{
public:
    std::shared_ptr<SceneManager> getManager();
private:
    std::shared_ptr<SceneManager> createManager();
    std::shared_ptr<SceneManager> manager;
};

#endif // SCENEMANAGERCREATOR_H
