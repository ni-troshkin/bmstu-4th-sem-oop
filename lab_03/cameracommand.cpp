#include "cameracommand.h"
#include "scenemanager.h"
#include "scenemanagercreator.h"
#include "transformmanager.h"
#include "transformmanagercreator.h"
#include "loadmanager.h"
#include "loadmanagercreator.h"
#include "exportmanager.h"
#include "exportmanagercreator.h"
#include "filecameraexporter.h"
#include "cameradirector.h"
#include "point.h"

AddCameraCommand::AddCameraCommand(const double x, const double y, const double z)
    :x(x), y(y), z(z) {}

void AddCameraCommand::execute()
{
    Point position(x, y, z);
    std::shared_ptr<Camera> camera(new Camera);
    camera->transform(position, position, position);
    SceneManagerCreator().getManager()->getScene()->addObject(camera);
}

RemoveCameraCommand::RemoveCameraCommand(const std::size_t &id)
    : id(id) {}

void RemoveCameraCommand::execute()
{
    SceneManagerCreator().getManager()->getScene()->removeObject(id);
}

MoveCameraCommand::MoveCameraCommand(const double dx, const double dy, const std::size_t id)
    : dx(dx), dy(dy), id(id) {}

void MoveCameraCommand::execute()
{
    Point move(dx, dy, 0);
    auto cameras_iter = SceneManagerCreator().getManager()->getScene()->begin();
    std::advance(cameras_iter, id);
    std::shared_ptr<Object> camera = *cameras_iter;

    TransformManagerCreator().getManager()->transformObject(camera, move, move, move);
}

SetCameraCommand::SetCameraCommand(const std::size_t id)
    : id(id) {}

void SetCameraCommand::execute()
{
    SceneManagerCreator().getManager()->setCamera(id);
}

LoadCameraCommand::LoadCameraCommand(const std::string filename)
    : filename(filename) {}

void LoadCameraCommand::execute()
{
    std::shared_ptr<LoadManager> load_man = LoadManagerCreator().getManager();
    load_man->setDirector(std::shared_ptr<BaseDirector>(new CameraDirector()));

    std::shared_ptr<Object> camera = load_man->load(filename);
    SceneManagerCreator().getManager()->getScene()->addObject(camera);
}


SaveCameraCommand::SaveCameraCommand(const std::string filename, std::size_t index)
    : filename(filename), index(index) {}

void SaveCameraCommand::execute()
{
    std::shared_ptr<ExportManager> export_man = ExportManagerCreator().getManager();
    export_man->setExporter(std::shared_ptr<BaseExporter>(new FileCameraExporter()));

    auto cameras_iter = SceneManagerCreator().getManager()->getScene()->begin();
    std::advance(cameras_iter, index);
    std::shared_ptr<Object> camera = *cameras_iter;

    export_man->save(filename, camera);
}
