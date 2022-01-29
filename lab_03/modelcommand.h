#ifndef MODELCOMMAND_H
#define MODELCOMMAND_H

#include <cstddef>
#include <string>
#include <memory>
#include "basecommand.h"
#include "object.h"

class ModelBaseCommand: public BaseCommand
{
};

class MoveModelCommand: public ModelBaseCommand
{
public:
    MoveModelCommand() = delete;
    MoveModelCommand(const double &dx, const double &dy, const double &dz, std::size_t id);

    virtual ~MoveModelCommand() override = default;
    virtual void execute() override;
private:
    double dx, dy, dz;
    std::size_t id;
};

class ScaleModelCommand: public ModelBaseCommand
{
public:
    ScaleModelCommand() = delete;
    ScaleModelCommand(const double &kx, const double &ky, const double &kz, std::size_t id);

    virtual ~ScaleModelCommand() override = default;
    virtual void execute() override;
private:
    double kx, ky, kz;
    std::size_t id;
};

class RotateModelCommand: public ModelBaseCommand
{
public:
    RotateModelCommand() = delete;
    RotateModelCommand(const double &thx, const double &thy, const double &thz, std::size_t id);

    virtual ~RotateModelCommand() override = default;
    virtual void execute() override;
private:
    double thx, thy, thz;
    std::size_t id;
};

class LoadModelCommand: public ModelBaseCommand
{
public:
    LoadModelCommand() = delete;
    LoadModelCommand(std::string filename);

    virtual ~LoadModelCommand() override = default;
    virtual void execute() override;
private:
    std::string filename;
};

class SaveModelCommand: public ModelBaseCommand
{
public:
    SaveModelCommand() = delete;
    SaveModelCommand(std::string filename, std::size_t index);

    virtual ~SaveModelCommand() override = default;
    virtual void execute() override;
private:
    std::string filename;
    std::size_t index;
};

class AddModelCommand: public ModelBaseCommand
{
public:
    AddModelCommand() = delete;
    AddModelCommand(std::shared_ptr<Object> model);

    virtual ~AddModelCommand() override = default;
    virtual void execute() override;
private:
    std::shared_ptr<Object> model;
};

class RemoveModelCommand: public ModelBaseCommand
{
public:
    RemoveModelCommand() = delete;
    RemoveModelCommand(std::size_t index);

    virtual ~RemoveModelCommand() override = default;
    virtual void execute() override;
private:
    std::size_t index;
};

#endif // MODELCOMMAND_H
