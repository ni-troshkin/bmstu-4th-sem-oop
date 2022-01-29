#include "drawmanagercreator.h"

std::shared_ptr<DrawManager> DrawManagerCreator::createManager()
{
    static std::shared_ptr<DrawManager> manager(new DrawManager());
    return manager;
}

std::shared_ptr<DrawManager> DrawManagerCreator::getManager()
{
    if (!manager)
        manager = createManager();

    return manager;
}
