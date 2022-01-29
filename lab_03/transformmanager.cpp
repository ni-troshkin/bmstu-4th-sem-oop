#include "transformmanager.h"

void TransformManager::transformObject(const std::shared_ptr<Object> &object, const Point &move, const Point &scale, const Point &rotate)
{
    object->transform(move, scale, rotate);
}
