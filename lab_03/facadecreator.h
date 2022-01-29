#ifndef FACADECREATOR_H
#define FACADECREATOR_H

#include <memory>
#include "facade.h"

class FacadeCreator
{
public:
    std::shared_ptr<Facade> getFacade();
protected:
    std::shared_ptr<Facade> createFacade();
private:
    std::shared_ptr<Facade> facade;
};

#endif // FACADECREATOR_H
