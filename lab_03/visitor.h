#ifndef VISITOR_H
#define VISITOR_H

#include "basevisitor.h"

class Visitor: public BaseVisitor
{
public:
    Visitor(const std::shared_ptr<BaseDrawer> &drawer);
    ~Visitor() = default;

    virtual void visit(const Camera &cam);
    virtual void visit(const Model &model);
    virtual void visit(const Composite &composite);
private:
    std::shared_ptr<BaseDrawer> drawer;
};

#endif // VISITOR_H
