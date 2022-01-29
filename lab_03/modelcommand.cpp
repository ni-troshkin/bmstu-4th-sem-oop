#include "modelcommand.h"
#include "transformmanagercreator.h"
#include "transformmanager.h"
#include "scenemanager.h"
#include "scenemanagercreator.h"
#include "loadmanager.h"
#include "loadmanagercreator.h"
#include "exportmanager.h"
#include "exportmanagercreator.h"
#include "filemodelexporter.h"
#include "modeldirector.h"

// Load / Save commands
// Export manager
// Exceptions

MoveModelCommand::MoveModelCommand(const double &dx, const double &dy, const double &dz, std::size_t id)
    : dx(dx), dy(dy), dz(dz), id(id) {}

void MoveModelCommand::execute()
{
    Point move(dx, dy, dz);
    Point scale(1, 1, 1);
    Point rotate(0, 0, 0);
    auto models_iter = SceneManagerCreator().getManager()->getScene()->begin();
    std::advance(models_iter, id);
    std::shared_ptr<Object> model = *models_iter;
    TransformManagerCreator().getManager()->transformObject(model, move, scale, rotate);
}

ScaleModelCommand::ScaleModelCommand(const double &kx, const double &ky, const double &kz, std::size_t id)
    : kx(kx), ky(ky), kz(kz), id(id) {}

void ScaleModelCommand::execute()
{
    Point move(0, 0, 0);
    Point scale(kx, ky, kz);
    Point rotate(0, 0, 0);
    auto models_iter = SceneManagerCreator().getManager()->getScene()->begin();
    std::advance(models_iter, id);
    std::shared_ptr<Object> model = *models_iter;
    TransformManagerCreator().getManager()->transformObject(model, move, scale, rotate);
}

RotateModelCommand::RotateModelCommand(const double &thx, const double &thy, const double &thz, std::size_t id)
    : thx(thx), thy(thy), thz(thz), id(id) {}

void RotateModelCommand::execute()
{
    Point move(0, 0, 0);
    Point scale(1, 1, 1);
    Point rotate(thx, thy, thz);
    auto models_iter = SceneManagerCreator().getManager()->getScene()->begin();
    std::advance(models_iter, id);
    std::shared_ptr<Object> model = *models_iter;
    TransformManagerCreator().getManager()->transformObject(model, move, scale, rotate);
}

LoadModelCommand::LoadModelCommand(std::string filename)
    : filename(filename) {}

void LoadModelCommand::execute()
{
    std::shared_ptr<LoadManager> load_man = LoadManagerCreator().getManager();
    load_man->setDirector(std::shared_ptr<BaseDirector>(new ModelDirector()));

    std::shared_ptr<Object> model = load_man->load(filename);
    SceneManagerCreator().getManager()->getScene()->addObject(model);
}

SaveModelCommand::SaveModelCommand(const std::string filename, std::size_t index)
    : filename(filename), index(index) {}

void SaveModelCommand::execute()
{
    std::shared_ptr<ExportManager> export_man = ExportManagerCreator().getManager();
    export_man->setExporter(std::shared_ptr<BaseExporter>(new FileModelExporter()));

    auto models_iter = SceneManagerCreator().getManager()->getScene()->begin();
    std::advance(models_iter, index);
    std::shared_ptr<Object> model = *models_iter;

    export_man->save(filename, model);
}


AddModelCommand::AddModelCommand(std::shared_ptr<Object> model)
    :model(std::move(model)) {}

void AddModelCommand::execute()
{
    SceneManagerCreator().getManager()->getScene()->addObject(model);
}

RemoveModelCommand::RemoveModelCommand(std::size_t index)
    :index(index) {}

void RemoveModelCommand::execute()
{
    SceneManagerCreator().getManager()->getScene()->removeObject(index);
}


//class LoadModelCommand: public ModelBaseCommand
//{
//public:
//    LoadModelCommand() = delete;
//    LoadModelCommand(std::string filename);

//    virtual ~LoadModelCommand() override = default;
//    virtual void execute() override;
//private:
//    std::string filename;
//};

//class SaveModelCommand: public ModelBaseCommand
//{
//public:
//    SaveModelCommand() = delete;
//    SaveModelCommand(std::string filename);

//    virtual ~SaveModelCommand() override = default;
//    virtual void execute() override;
//private:
//    std::string filename;
//};
