#ifndef MODELIMPLEMENTATION_H
#define MODELIMPLEMENTATION_H

#include <vector>

#include "point.h"
#include "edge.h"

class ModelImplementation
{
public:
    ModelImplementation() = default;
    ModelImplementation(std::vector<Point> &points, std::vector<Edge> &edges);
    ModelImplementation(Point &center, std::vector<Point> &points, std::vector<Edge> &edges);
    ~ModelImplementation() = default;

    void setCenter(const Point &point);
    void addPoint(const Point &point);
    void addEdge(const Edge &edge);

    const Point& getCenter() const;
    const std::vector<Point>& getPoints() const;
    const std::vector<Edge>& getEdges() const;

    void transform(const Point &move, const Point &scale, const Point &rotate);

private:
    Point center;
    std::vector<Point> points;
    std::vector<Edge> edges;
};

#endif // MODELIMPLEMENTATION_H
