#ifndef FILESCENELOADER_H
#define FILESCENELOADER_H

#include "basesceneloader.h"
#include "scenebuilder.h"

class FileSceneLoader: public BaseSceneLoader
{
public:
    FileSceneLoader();
    explicit FileSceneLoader(std::shared_ptr<std::ifstream> input);
    virtual ~FileSceneLoader() override = default;

    virtual void open(std::string filename) override;
    virtual void close() override;

    virtual std::size_t loadIndex(std::size_t max_index) override;
    virtual double loadCoordinate() override;
    virtual std::size_t loadSize() override;
private:

    std::shared_ptr<std::ifstream> file;
    std::shared_ptr<SceneBuilder> builder;
};

#endif // FILESCENELOADER_H
