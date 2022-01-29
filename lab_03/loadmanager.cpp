#include "loadmanager.h"

LoadManager::LoadManager(std::shared_ptr<BaseDirector> director)
    : director(std::move(director)) {}

void LoadManager::setDirector(const std::shared_ptr<BaseDirector> director)
{
    this->director = director;
}

std::shared_ptr<Object> LoadManager::load(std::string filename)
{
    return director->build(filename);
}
