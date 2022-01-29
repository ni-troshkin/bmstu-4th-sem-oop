#ifndef QTFACTORY_H
#define QTFACTORY_H

#include "abstractgraphicsfactory.h"
#include <QGraphicsScene>

class QTFactory: public AbstractGraphicsFactory
{
public:
    QTFactory() = default;
    explicit QTFactory(std::shared_ptr<QGraphicsScene> scene);
    ~QTFactory() = default;

    virtual std::shared_ptr<BaseDrawer> createGraphics() override;
private:
    std::shared_ptr<QGraphicsScene> scene;
};

#endif // QTFACTORY_H
