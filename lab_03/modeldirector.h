#ifndef MODELDIRECTOR_H
#define MODELDIRECTOR_H

#include "basedirector.h"
#include "modelbuilder.h"
#include "basemodelloader.h"

class ModelDirector: public BaseDirector
{
public:
    explicit ModelDirector();
    ModelDirector(std::shared_ptr<BaseModelLoader> loader, std::shared_ptr<ModelBuilder> builder);
    ~ModelDirector() = default;

    virtual std::shared_ptr<Object> build(std::string source) override;

private:
    std::shared_ptr<BaseModelLoader> loader;
    std::shared_ptr<ModelBuilder> builder;
};

#endif // MODELDIRECTOR_H
