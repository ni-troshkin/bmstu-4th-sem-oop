#ifndef SCENEDIRECTOR_H
#define SCENEDIRECTOR_H

#include "basedirector.h"
#include "scenebuilder.h"
#include "basesceneloader.h"

class SceneDirector: public BaseDirector
{
public:
    explicit SceneDirector();
    SceneDirector(std::shared_ptr<BaseSceneLoader> loader, std::shared_ptr<SceneBuilder> builder);
    ~SceneDirector() = default;

    virtual std::shared_ptr<Object> build(std::string source) override;

private:
    std::shared_ptr<BaseSceneLoader> loader;
    std::shared_ptr<SceneBuilder> builder;
};

#endif // SCENEDIRECTOR_H
