#ifndef EXPORTMANAGERCREATOR_H
#define EXPORTMANAGERCREATOR_H

#include <memory>
#include "exportmanager.h"

class ExportManagerCreator
{
public:
    std::shared_ptr<ExportManager> getManager();
private:
    std::shared_ptr<ExportManager> createManager();
    std::shared_ptr<ExportManager> manager;
};

#endif // EXPORTMANAGERCREATOR_H
