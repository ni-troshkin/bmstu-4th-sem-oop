#include "transformmanagercreator.h"

std::shared_ptr<TransformManager> TransformManagerCreator::createManager()
{
    static std::shared_ptr<TransformManager> manager(new TransformManager());
    return manager;
}

std::shared_ptr<TransformManager> TransformManagerCreator::getManager()
{
    if (!manager)
        manager = createManager();

    return manager;
}
