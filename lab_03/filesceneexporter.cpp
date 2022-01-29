#include "filesceneexporter.h"
#include "filemodelexporter.h"
#include "filecameraexporter.h"
#include "scene.h"
#include <iostream>
#include <fstream>

FileSceneExporter::FileSceneExporter()
{}

FileSceneExporter::FileSceneExporter(std::shared_ptr<std::ofstream> output)
    : file(std::move(output)) {}

void FileSceneExporter::open(std::string filename)
{
    file = std::shared_ptr<std::ofstream>(new std::ofstream(filename));
//    if (!*file) throw exception
}

void FileSceneExporter::close()
{
    file->close();
}


void FileSceneExporter::save(std::shared_ptr<Object> object)
{
    std::shared_ptr<Scene> scene = std::dynamic_pointer_cast<Scene>(object);

    auto obj_iter = scene->begin();
    for (; obj_iter != scene->end(); obj_iter++)
        FileModelExporter(file).save(*obj_iter);
}

void FileSceneExporter::saveModels(std::vector<std::shared_ptr<Object>> models)
{
    *file << models.size() << std::endl;
    for (auto model: models)
        FileModelExporter(file).save(model);
}

void FileSceneExporter::saveCameras(std::vector<std::shared_ptr<Object>> cameras)
{
    *file << cameras.size() << std::endl;
    for (auto camera: cameras)
        FileCameraExporter(file).save(camera);
}












//    auto models_iter = SceneManagerCreator().getManager()->getScene()->begin();
//    std::advance(models_iter, id);
//    std::shared_ptr<Object> model = *models_iter;

//    std::vector<std::shared_ptr<Object>> models = scene->getModels();
//    std::vector<std::shared_ptr<Object>> cameras = scene->getCameras();

//    saveModels(models);
//    saveCameras(cameras);
