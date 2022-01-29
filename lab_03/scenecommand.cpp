#include "scenecommand.h"
#include "drawmanager.h"
#include "drawmanagercreator.h"
#include "scenemanager.h"
#include "scenemanagercreator.h"
#include "exportmanager.h"
#include "exportmanagercreator.h"
#include "filesceneexporter.h"
#include "scenedirector.h"
#include "loadmanager.h"
#include "loadmanagercreator.h"

RenderSceneCommand::RenderSceneCommand(std::shared_ptr<BaseDrawer> drawer)
    : drawer(std::move(drawer)) {}

void RenderSceneCommand::execute()
{
    std::shared_ptr<DrawManager> draw_man = DrawManagerCreator().getManager();
    std::shared_ptr<SceneManager> scene_man = SceneManagerCreator().getManager();

    drawer->clearScene();
    draw_man->setDrawer(drawer);
    draw_man->setCamera(scene_man->getCamera());
    std::shared_ptr<Visitor> visitor(new Visitor(drawer));
    scene_man->getScene()->accept(visitor);
}

SaveSceneCommand::SaveSceneCommand(std::string source)
    : source(source) {}

void SaveSceneCommand::execute()
{
    std::shared_ptr<ExportManager> export_man = ExportManagerCreator().getManager();
    std::shared_ptr<SceneManager> scene_man = SceneManagerCreator().getManager();

    export_man->setExporter(std::shared_ptr<BaseExporter>(new FileSceneExporter()));
    export_man->save(source, std::dynamic_pointer_cast<Object>(scene_man->getScene()));
}

LoadSceneCommand::LoadSceneCommand(std::string source)
    :source(source) {}

void LoadSceneCommand::execute()
{
    std::shared_ptr<LoadManager> load_man = LoadManagerCreator().getManager();
    load_man->setDirector(std::shared_ptr<BaseDirector>(new SceneDirector));

    std::shared_ptr<Object> scene = load_man->load(source);
    SceneManagerCreator().getManager()->setScene(std::dynamic_pointer_cast<Scene>(scene));
}

// LOAD SAVE

ClearSceneCommand::ClearSceneCommand(std::shared_ptr<BaseDrawer> drawer)
    : drawer(std::move(drawer)) {}

void ClearSceneCommand::execute()
{
    drawer->clearScene();
}
