#ifndef FACADE_H
#define FACADE_H

#include "basecommand.h"
#include <memory>

class Facade
{
public:
    Facade() = default;
    Facade(const Facade &facade) = delete;
    Facade& operator=(const Facade &facade) = delete;

    void execute(std::shared_ptr<BaseCommand> &command);
};

#endif // FACADE_H
