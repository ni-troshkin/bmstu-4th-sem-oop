#include "object.h"

bool Object::add(const std::shared_ptr<Object> &obj)
{
    return false;
}

bool Object::remove(const Iterator &iterator)
{
    return false;
}

Iterator Object::begin()
{
    return Iterator();
}

Iterator Object::end()
{
    return Iterator();
}

ConstIterator Object::cbegin() const
{
    return ConstIterator();
}

ConstIterator Object::cend() const
{
    return ConstIterator();
}

ConstIterator Object::begin() const
{
    return ConstIterator();
}

ConstIterator Object::end() const
{
    return ConstIterator();
}

bool Object::isVisible()
{
    return false;
}

bool Object::isComposite()
{
    return false;
}

bool VisibleObject::isVisible()
{
    return true;
}

bool InvisibleObject::isVisible()
{
    return false;
}
