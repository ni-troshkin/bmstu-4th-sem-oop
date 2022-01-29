#ifndef LOADMANAGERCREATOR_H
#define LOADMANAGERCREATOR_H

#include <memory>
#include "loadmanager.h"

class LoadManagerCreator
{
public:
    std::shared_ptr<LoadManager> getManager();
private:
    std::shared_ptr<LoadManager> createManager();
    std::shared_ptr<LoadManager> manager;
};

#endif // LOADMANAGERCREATOR_H
