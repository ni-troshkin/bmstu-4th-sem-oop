#include "filesceneloader.h"
#include "filemodelloader.h"
#include "filecameraloader.h"
#include <iostream>
#include <fstream>

FileSceneLoader::FileSceneLoader()
{
    builder = std::shared_ptr<SceneBuilder>(new SceneBuilder);
}

FileSceneLoader::FileSceneLoader(std::shared_ptr<std::ifstream> input)
    : file(std::move(input))
{
    builder = std::shared_ptr<SceneBuilder>(new SceneBuilder());
}

void FileSceneLoader::open(std::string filename)
{
    file = std::shared_ptr<std::ifstream>(new std::ifstream(filename));
//    if (!*file) throw exception
}

void FileSceneLoader::close()
{
    file->close();
}

std::size_t FileSceneLoader::loadIndex(std::size_t max_index)
{
    std::size_t index;
    *file >> index;
    if (index > max_index)
        return max_index;
    return index;
}

double FileSceneLoader::loadCoordinate()
{
    double coord;
    *file >> coord;
    return coord;
}

std::size_t FileSceneLoader::loadSize()
{
    std::size_t size;
    *file >> size;
    return size;
}













































//std::shared_ptr<Object> FileSceneLoader::load()
//{
//    builder->reset();
//    loadModels();
//    loadCameras();
//    std::shared_ptr<Scene> scene = builder->get();
//    return std::dynamic_pointer_cast<Object>(scene);
//}


//void FileSceneLoader::save(std::shared_ptr<Object> scene)
//{
//    std::vector<std::shared_ptr<Object>> models = scene->getModels();
//    *file << models.count() << std::endl;

//    for (auto model : models)
//        FileModelLoader().save(model);

//    std::vector<std::shared_ptr<Camera>> cameras = scene.getCameras();
//    *file << cameras.count() << std::endl;

//    for (auto camera : cameras)
//        FileCameraLoader().save(camera);
//}

//void FileSceneLoader::loadModels()
//{
//    std::size_t count;
//    *file >> count;

//    for (std::size_t i = 0; i < count; i++)
//        builder->buildModel(FileModelLoader().load());
//}

//void FileSceneLoader::loadCameras()
//{
//    std::size_t count;
//    *file >> count;

//    for (std::size_t i = 0; i < count; i++)
//        builder->buildCamera(FileCameraLoader().load());
//}
