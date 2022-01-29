#include "scenedirector.h"
#include "modeldirector.h"
#include "cameradirector.h"

SceneDirector::SceneDirector() {}

SceneDirector::SceneDirector(std::shared_ptr<BaseSceneLoader> loader, std::shared_ptr<SceneBuilder> builder)
    : loader(std::move(loader)), builder(std::move(builder)) {}

std::shared_ptr<Object> SceneDirector::build(std::string source)
{
    loader->open(source);

    builder->reset();
    std::size_t model_count;
    model_count = loader->loadSize();

    loader->close();

    for (std::size_t i = 0; i < model_count; i++)
        builder->buildModel(ModelDirector().build(source));

    loader->open(source);
    std::size_t camera_count;
    camera_count = loader->loadSize();

    loader->close();

    for (std::size_t i = 0; i < camera_count; i++)
        builder->buildCamera(CameraDirector().build(source));

    std::shared_ptr<Scene> scene = builder->get();
    return std::dynamic_pointer_cast<Object>(scene);
}
