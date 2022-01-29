#include "scenemanager.h"
#include <iostream>

SceneManager::SceneManager()
{
    scene = std::make_shared<Scene>();
}

std::shared_ptr<Scene> SceneManager::getScene() const {
    return scene;
}

std::shared_ptr<Camera> SceneManager::getCamera() const {
    return camera;
}

void SceneManager::setScene(std::shared_ptr<Scene> scene) {
    this->scene = std::move(scene);
}

void SceneManager::setCamera(const std::size_t &number) {
    auto cameras_begin = scene->begin();
    auto cameras_end = scene->end();
    auto size = cameras_end - cameras_begin;
//    std::advance(cameras_iter, id);
//    std::shared_ptr<Object> camera = *cameras_iter;

    std::cout << size << std::endl;
    std::advance(cameras_begin, number);
    std::shared_ptr<Object> camera = *cameras_begin;

    this->camera = std::dynamic_pointer_cast<Camera>(camera);
}
