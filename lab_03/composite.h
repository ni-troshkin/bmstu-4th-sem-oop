#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "object.h"

class Composite: public Object
{
public:
    Composite() = default;
    Composite(std::shared_ptr<Object> &component);
    Composite(const std::vector<std::shared_ptr<Object>> &comps);

    std::size_t size() const;

    virtual bool add(const std::shared_ptr<Object> &obj) override;
    virtual bool remove(const Iterator &iterator) override;

    virtual Iterator begin() override;
    virtual Iterator end() override;

    virtual bool isVisible() override;
    virtual bool isComposite() override;

    virtual void transform(const Point &move, const Point &scale, const Point &rotate) override;
    virtual void accept(std::shared_ptr<BaseVisitor> visitor) override;

    /*virtual*/ std::vector<std::shared_ptr<Object>> &getObjects(); //override;

private:
    std::vector<std::shared_ptr<Object>> objects;
};

#endif // COMPOSITE_H
