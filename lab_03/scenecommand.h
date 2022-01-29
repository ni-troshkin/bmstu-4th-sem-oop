#ifndef SCENECOMMAND_H
#define SCENECOMMAND_H

#include <string>
#include <memory>
#include "basecommand.h"
#include "basedrawer.h"

class SceneBaseCommand: public BaseCommand
{
};

class RenderSceneCommand: public SceneBaseCommand
{
public:
    RenderSceneCommand() = delete;
    RenderSceneCommand(std::shared_ptr<BaseDrawer> drawer);
    virtual ~RenderSceneCommand() override = default;

    virtual void execute() override;
private:
    std::shared_ptr<BaseDrawer> drawer;
};

class LoadSceneCommand: public SceneBaseCommand
{
public:
    LoadSceneCommand() = delete;
    LoadSceneCommand(std::string source);
    virtual ~LoadSceneCommand() override = default;

    virtual void execute() override;
private:
    std::string source;
};

class SaveSceneCommand: public SceneBaseCommand
{
public:
    SaveSceneCommand() = delete;
    SaveSceneCommand(std::string source);
    virtual ~SaveSceneCommand() override = default;

    virtual void execute() override;
private:
    std::string source;
};

class ClearSceneCommand: public SceneBaseCommand
{
public:
    ClearSceneCommand() = delete;
    ClearSceneCommand(std::shared_ptr<BaseDrawer> drawer);
    virtual ~ClearSceneCommand() override = default;

    virtual void execute() override;
private:
    std::shared_ptr<BaseDrawer> drawer;
};

#endif // SCENECOMMAND_H
