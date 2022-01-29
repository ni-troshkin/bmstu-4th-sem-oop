#include "modelimplementation.h"
#include <iostream>
ModelImplementation::ModelImplementation(std::vector<Point> &points, std::vector<Edge> &edges)
    : center{}, points(points), edges(edges) {}

ModelImplementation::ModelImplementation(Point &center, std::vector<Point> &points, std::vector<Edge> &edges)
    : center(center), points(points), edges(edges) {}


void ModelImplementation::addPoint(const Point &point)
{
    points.push_back(point);
}

void ModelImplementation::addEdge(const Edge &edge)
{
    edges.push_back(edge);
}

void ModelImplementation::setCenter(const Point &point)
{
    center = Point(point);
}

const Point& ModelImplementation::getCenter() const
{
    return center;
}

const std::vector<Point> &ModelImplementation::getPoints() const
{
    return points;
}

const std::vector<Edge> &ModelImplementation::getEdges() const
{
    return edges;
}

void ModelImplementation::transform(const Point &move, const Point &scale, const Point &rotate)
{
    std::cout << "HERE TRANS " << points.size() << " POINTS" << std::endl;

    Point movement(center);
    movement = movement - center - center;

    for (auto &point: points)
        point.move(movement.get_x(), movement.get_y(), movement.get_z());

    center.move(move.get_x(), move.get_y(), move.get_z());

    for (auto &point : points)
    {
        point.move(move.get_x(), move.get_y(), move.get_z());
        point.scale(scale.get_x(), scale.get_y(), scale.get_z());
        point.rotate(rotate.get_x(), rotate.get_y(), rotate.get_z());
    }

    for (auto &point: points)
        point.move(center.get_x(), center.get_y(), center.get_z());
}
