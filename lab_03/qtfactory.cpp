#include "qtfactory.h"
#include "qtdrawer.h"

QTFactory::QTFactory(std::shared_ptr<QGraphicsScene> scene)
    : scene(std::move(scene)) {}

std::shared_ptr<BaseDrawer> QTFactory::createGraphics()
{
    return std::shared_ptr<BaseDrawer>(new QTDrawer(scene));
}
