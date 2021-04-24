#ifndef BASE_CONTAINER_H
#define BASE_CONTAINER_H

#include <cstdlib>

class BaseContainer
{   
public:
    BaseContainer(std::size_t size = 0);

    virtual std::size_t get_size() const;

    virtual operator bool() const;

    virtual ~BaseContainer() = 0;

protected:
    std::size_t size;
};

#endif // BASE_CONTAINER_H
