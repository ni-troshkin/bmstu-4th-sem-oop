#include "loadmanagercreator.h"

std::shared_ptr<LoadManager> LoadManagerCreator::createManager()
{
    static std::shared_ptr<LoadManager> manager(new LoadManager());
    return manager;
}

std::shared_ptr<LoadManager> LoadManagerCreator::getManager()
{
    if (!manager)
        manager = createManager();

    return manager;
}
