#include "scenemanagercreator.h"

std::shared_ptr<SceneManager> SceneManagerCreator::getManager()
{
    if (!manager)
        manager = createManager();

    return manager;
}

std::shared_ptr<SceneManager> SceneManagerCreator::createManager()
{
    static std::shared_ptr<SceneManager> manager(new SceneManager);
    return manager;
}
