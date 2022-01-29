#include "facadecreator.h"

std::shared_ptr<Facade> FacadeCreator::getFacade()
{
    if (!facade)
        facade = createFacade();

    return facade;
}

std::shared_ptr<Facade> FacadeCreator::createFacade()
{
    return std::shared_ptr<Facade>(new Facade);
}
