#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <memory>

#include "point.h"
#include "visitor.h"

class Object;
//class Visitor;

using Iterator = std::vector<std::shared_ptr<Object>>::iterator;
using ConstIterator = std::vector<std::shared_ptr<Object>>::const_iterator;

class Object
{
public:
    Object() = default;
    virtual ~Object() = default;

    virtual bool add(const std::shared_ptr<Object> &obj);
    virtual bool remove(const Iterator &iterator);

    virtual Iterator begin();
    virtual Iterator end();

    virtual ConstIterator begin() const;
    virtual ConstIterator end() const;

    virtual ConstIterator cbegin() const;
    virtual ConstIterator cend() const;

    virtual bool isVisible();
    virtual bool isComposite();

    virtual void accept(std::shared_ptr<BaseVisitor> visitor) = 0;
    virtual void transform(const Point &move, const Point &scale, const Point &rotate) = 0;
//    virtual std::vector<std::shared_ptr<Object>> &getObjects() = 0;
};

class VisibleObject: public Object
{
public:
    VisibleObject() = default;
    virtual ~VisibleObject() override = default;

    virtual bool isVisible() override;
};

class InvisibleObject: public Object
{
public:
    InvisibleObject() = default;
    virtual ~InvisibleObject() override = default;

    virtual bool isVisible() override;
};

#endif // OBJECT_H
