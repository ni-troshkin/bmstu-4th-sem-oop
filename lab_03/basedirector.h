#ifndef BASEDIRECTOR_H
#define BASEDIRECTOR_H

#include <memory>
#include "object.h"

class BaseDirector
{
public:
    BaseDirector() = default;
    virtual ~BaseDirector() = 0;

    virtual std::shared_ptr<Object> build(const std::string source) = 0;
};

#endif // BASEDIRECTOR_H
