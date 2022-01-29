#ifndef ABSTRACTGRAPHICSFACTORY_H
#define ABSTRACTGRAPHICSFACTORY_H

#include "basedrawer.h"
#include <memory>

class AbstractGraphicsFactory
{
public:
    virtual std::shared_ptr<BaseDrawer> createGraphics() = 0;
};

#endif // ABSTRACTGRAPHICSFACTORY_H
