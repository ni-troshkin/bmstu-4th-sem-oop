#include "modelbuilder.h"
#include <iostream>

void ModelBuilder::reset()
{
    model = std::make_shared<ModelImplementation>();
}

void ModelBuilder::buildEdge(const std::size_t from, const std::size_t to)
{
    model->addEdge(Edge(from, to));
}

void ModelBuilder::buildPoint(const double x, const double y, const double z)
{
    model->addPoint(Point(x, y, z));
    std::cout << "LOADED " << model->getPoints().size() << " POINTS" << std::endl;
    std::cout << x << " " << y << " " << z << std::endl;
}

void ModelBuilder::buildCenter(const double x, const double y, const double z)
{
    model->setCenter(Point(x, y, z));
}

std::shared_ptr<Model> ModelBuilder::get()
{
    std::cout << "LOADED " << model->getPoints().size() << " POINTS" << std::endl;
    return std::make_shared<Model>(model);
}
