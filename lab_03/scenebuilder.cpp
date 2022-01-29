#include "scenebuilder.h"

std::shared_ptr<Scene> SceneBuilder::get()
{
    return scene;
}

void SceneBuilder::reset()
{
    scene = std::shared_ptr<Scene>(new Scene());
}

void SceneBuilder::buildModel(const std::shared_ptr<Object> model)
{
    scene->addObject(model);
}

void SceneBuilder::buildCamera(const std::shared_ptr<Object> camera)
{
    scene->addObject(camera);
}
