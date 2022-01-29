#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include <memory>
#include <string>
#include "basemanager.h"
#include "basedirector.h"
#include "object.h"

class LoadManager: public BaseManager
{
public:
    LoadManager() = default;
    LoadManager(std::shared_ptr<BaseDirector> director);
    LoadManager(const LoadManager &manager) = delete;
    LoadManager& operator=(const LoadManager &manager) = delete;

    ~LoadManager() = default;
    void setDirector(const std::shared_ptr<BaseDirector> director);
    std::shared_ptr<Object> load(std::string filename);
    void save(std::string filename);

private:
    std::shared_ptr<BaseDirector> director;
};

#endif // LOADMANAGER_H
