#include "qtdrawer.h"
#include <iostream>

QTDrawer::QTDrawer()
    :scene(nullptr) {}

QTDrawer::QTDrawer(std::shared_ptr<QGraphicsScene> scene)
    : scene(std::move(scene)) {}

void QTDrawer::drawLine(const Point &from, const Point &to)
{
    std::cout << from.get_x() << " " << from.get_y() << " " << to.get_x() << " " << to.get_y() << std::endl;
    scene->addLine(from.get_x(), from.get_y(), to.get_x(), to.get_y());
}

void QTDrawer::clearScene()
{
    scene->clear();
}
