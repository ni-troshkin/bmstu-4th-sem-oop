#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include <cstddef>
#include <memory>
#include "basebuilder.h"
#include "model.h"

class ModelBuilder//: public BaseBuilder
{
public:
    ModelBuilder() : model(nullptr) {};
    ~ModelBuilder() = default;

//    virtual void build() override;
    void reset();
    std::shared_ptr<Model> get();
    void buildCenter(const double x, const double y, const double z);
//    void buildPoints(std::vector<Point> &points);
//    void buildEdges(std::vector<Edge> &edges);
    void buildPoint(const double x, const double y, const double z);
    void buildEdge(const std::size_t from, const std::size_t to);

private:
    std::shared_ptr<ModelImplementation> model;
};

#endif // MODELBUILDER_H
