#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include "object.h"
#include "modelimplementation.h"

class Visitor;

class Model: public VisibleObject
{
public:
    Model();
    Model(const std::shared_ptr<ModelImplementation> imp);
    Model(const Model &model);
    virtual ~Model() = default;

    virtual bool isComposite();

    virtual void transform(const Point &move, const Point &scale, const Point &rotate);
    virtual void accept(std::shared_ptr<BaseVisitor> visitor);

    std::shared_ptr<ModelImplementation> getImplementation() const;

private:
    std::shared_ptr<ModelImplementation> implementation;
};

#endif // MODEL_H
