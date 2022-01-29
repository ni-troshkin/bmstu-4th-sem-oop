#include "scene.h"
#include <iterator>
#include <iostream>

Scene::Scene()
{
    objects = std::make_shared<Composite>();
}

Iterator Scene::begin()
{
    return objects->begin();
}

Iterator Scene::end()
{
    return objects->end();
}

ConstIterator Scene::begin() const
{
    return objects->begin();
}

ConstIterator Scene::end() const
{
    return objects->end();
}

ConstIterator Scene::cbegin() const
{
    return objects->cbegin();
}

ConstIterator Scene::cend() const
{
    return objects->cend();
}

void Scene::addObject(const std::shared_ptr<Object> &object)
{
    objects->add(object);
}

void Scene::removeObject(const std::size_t index)
{
    auto object_iter = begin();
    std::advance(object_iter, index);
    objects->remove(object_iter);
}

void Scene::accept(std::shared_ptr<BaseVisitor> visitor)
{
    objects->accept(visitor);
}



























//void Scene::addModel(const std::shared_ptr<Object> &model) {
//    std::cout << "added model" << std::endl;
//    models->add(model);
//}

//void Scene::removeModel(const std::size_t index) {
//    auto it = models->begin();
//    std::advance(it, index);
//    models->remove(it);
//}

//void Scene::addCamera(const std::shared_ptr<Object> &camera) {
//    cameras->add(camera);
//}

//void Scene::removeCamera(const std::size_t index) {
//    auto it = cameras->begin();
//    std::advance(it, index);
//    cameras->remove(it);
//}

//std::vector<std::shared_ptr<Object>> Scene::getModels() {
//    std::cout << models->getObjects().size() << std::endl;
//    return models->getObjects();
//}

//std::vector<std::shared_ptr<Object>> Scene::getCameras() {
//    return cameras->getObjects();
//}

//std::shared_ptr<Composite> Scene::getComposite()
//{
//    std::cout << "SIZE" << models->getObjects().size() << std::endl;
//    return models;
//}
