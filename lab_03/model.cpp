#include "model.h"
#include <iostream>
Model::Model(const std::shared_ptr<ModelImplementation> imp)
    : implementation(std::move(imp)) {}

bool Model::isComposite()
{
    return false;
}

void Model::transform(const Point &move, const Point &scale, const Point &rotate)
{
    implementation->transform(move, scale, rotate);
}

void Model::accept(std::shared_ptr<BaseVisitor> visitor)
{
    std::cout << getImplementation()->getPoints().size() << "POINTS" << std::endl;
    visitor->visit(*this);
}

std::shared_ptr<ModelImplementation> Model::getImplementation() const
{
    return implementation;
}
