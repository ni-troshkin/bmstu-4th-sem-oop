#include "composite.h"
#include <iostream>

Composite::Composite(std::shared_ptr<Object> &component)
{
    objects.push_back(component);
}

Composite::Composite(const std::vector<std::shared_ptr<Object>> &comps)
{
    objects = comps;
}


bool Composite::add(const std::shared_ptr<Object> &obj)
{
    objects.push_back(obj);
    std::cout << objects.size() << std::endl;
    return true;
}

bool Composite::remove(const Iterator &iterator)
{
    objects.erase(iterator);
    return true;
}

Iterator Composite::begin()
{
    return objects.begin();
}

Iterator Composite::end()
{
    return objects.end();
}

bool Composite::isVisible()
{
    return false;
}

bool Composite::isComposite()
{
    return true;
}

std::size_t Composite::size() const
{
    return objects.size();
}

void Composite::transform(const Point &move, const Point &scale, const Point &turn)
{
    for (const auto &elem : objects)
        elem->transform(move, scale, turn);
}

void Composite::accept(std::shared_ptr<BaseVisitor> visitor)
{
    std::cout << "SIZE " << objects.size() << std::endl;
    for (const auto &obj : objects)
    {
        std::cout << "ACCEPTION";
        obj->accept(visitor);
    }
}

std::vector<std::shared_ptr<Object>> &Composite::getObjects()
{
    return objects;
}
