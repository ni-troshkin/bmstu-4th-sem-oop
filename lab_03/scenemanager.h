#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "basemanager.h"
#include "scene.h"

class SceneManager: public BaseManager
{
public:
    SceneManager();
    SceneManager(const SceneManager &manager) = delete;
    SceneManager& operator=(const SceneManager &manager) = delete;

    ~SceneManager() = default;

    std::shared_ptr<Camera> getCamera() const;
    std::shared_ptr<Scene> getScene() const;

    void setCamera(const std::size_t &number);
    void setScene(std::shared_ptr<Scene> scene);

private:
    std::shared_ptr<Scene> scene;
    std::shared_ptr<Camera> camera;
};

#endif // SCENEMANAGER_H
