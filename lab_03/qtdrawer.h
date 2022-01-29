#ifndef QTDRAWER_H
#define QTDRAWER_H

#include "basedrawer.h"
#include <QtWidgets>
#include <QtWidgets/QGraphicsScene>

class QTDrawer: public BaseDrawer
{
public:
    QTDrawer();
    QTDrawer(std::shared_ptr<QGraphicsScene> scene);

    virtual void drawLine(const Point &from, const Point &to) override;
    virtual void clearScene() override;
private:
    std::shared_ptr<QGraphicsScene> scene;
};

#endif // QTDRAWER_H
