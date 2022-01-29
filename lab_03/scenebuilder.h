#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include <memory>
#include "basebuilder.h"
#include "scene.h"

class SceneBuilder//: public BaseBuilder
{
public:
    SceneBuilder() = default;
    ~SceneBuilder() = default;

//    virtual void build() override;
    void reset();
    void buildModel(const std::shared_ptr<Object> model);
    void buildCamera(const std::shared_ptr<Object> camera);
    std::shared_ptr<Scene> get();

private:
    std::shared_ptr<Scene> scene;
};

#endif // SCENEBUILDER_H
