#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <memory>

#include "composite.h"
#include "camera.h"
#include "model.h"

class Scene
{
public:
    Scene();
    virtual ~Scene() = default;

    void addObject(const std::shared_ptr<Object> &object);
    void removeObject(const std::size_t id);

    Iterator begin();
    Iterator end();

    ConstIterator begin() const;
    ConstIterator end() const;

    ConstIterator cbegin() const;
    ConstIterator cend() const;

    void accept(std::shared_ptr<BaseVisitor> visitor);

private:
     std::shared_ptr<Object> objects;
};

#endif // SCENE_H
