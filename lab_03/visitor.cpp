#include "visitor.h"
#include <vector>
class Point;
#include "model.h"
#include "drawmanager.h"
#include "drawmanagercreator.h"
#include <iostream>

Visitor::Visitor(const std::shared_ptr<BaseDrawer> &drawer)
    : drawer(drawer) {}

void Visitor::visit(const Model &model)
{
    std::cout << "VISIT" << std::endl;
    std::vector<Point> points = model.getImplementation()->getPoints();
    std::cout << points.size() << " points" << std::endl;

    Point center = model.getImplementation()->getCenter();
    for (Point &pt: points)
    {
        pt = DrawManagerCreator().getManager()->proection(pt);
        std::cout << pt.get_x() << pt.get_y() << pt.get_z();
    }

    std::cout << "Transformed points" << std::endl;
    for (auto edge : model.getImplementation()->getEdges())
        drawer->drawLine(
                points.at(edge.getFrom()),
                points.at(edge.getTo()));
}

void Visitor::visit(const Camera &camera) {}

void Visitor::visit(const Composite &composite) {}

