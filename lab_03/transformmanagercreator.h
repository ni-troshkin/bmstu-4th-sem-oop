#ifndef TRANSFORMMANAGERCREATOR_H
#define TRANSFORMMANAGERCREATOR_H

#include "transformmanager.h"

class TransformManagerCreator
{
public:
    std::shared_ptr<TransformManager> getManager();
private:
    std::shared_ptr<TransformManager> createManager();
    std::shared_ptr<TransformManager> manager;
};

#endif // TRANSFORMMANAGERCREATOR_H
