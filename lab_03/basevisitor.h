#ifndef BASEVISITOR_H
#define BASEVISITOR_H

class Camera;
class Model;
class Scene;

#include "modelimplementation.h"
#include "basedrawer.h"
#include <memory>
class Composite;

class BaseVisitor
{
public:
//    friend class BaseDrawer;
    BaseVisitor() = default;
    virtual ~BaseVisitor() = default;

    virtual void visit(const Camera &cam) = 0;
    virtual void visit(const Model &model) = 0;
    virtual void visit(const Composite &composite) = 0;

private:
    std::shared_ptr<BaseDrawer> drawer;
};

#endif // BASEVISITOR_H
