#include "base_container.h"

BaseContainer::BaseContainer(std::size_t size)
    : size(size)
{
}

std::size_t BaseContainer::get_size() const
{
    return size;
}

BaseContainer::operator bool() const
{
    return size;
}

BaseContainer::~BaseContainer() = default;
