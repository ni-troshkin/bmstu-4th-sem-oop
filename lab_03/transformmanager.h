#ifndef TRANSFORMMANAGER_H
#define TRANSFORMMANAGER_H

#include <memory>
#include "basemanager.h"
#include "object.h"

class TransformManager: public BaseManager
{
public:
    TransformManager() = default;
    TransformManager(const TransformManager &manager) = delete;
    TransformManager& operator=(const TransformManager &manager) = delete;

    ~TransformManager() = default;

    void transformObject(const std::shared_ptr<Object> &object, const Point &move, const Point &scale, const Point &rotate);
};

#endif // TRANSFORMMANAGER_H
