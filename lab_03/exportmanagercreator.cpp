#include "exportmanagercreator.h"

std::shared_ptr<ExportManager> ExportManagerCreator::createManager()
{
    static std::shared_ptr<ExportManager> manager(new ExportManager());
    return manager;
}

std::shared_ptr<ExportManager> ExportManagerCreator::getManager()
{
    if (!manager)
        manager = createManager();

    return manager;
}
