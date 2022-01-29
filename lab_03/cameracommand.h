#ifndef CAMERACOMMAND_H
#define CAMERACOMMAND_H

#include <cstddef>
#include <string>
#include "basecommand.h"

class CameraBaseCommand: public BaseCommand
{
};

class AddCameraCommand: public CameraBaseCommand
{
public:
    AddCameraCommand() = delete;
    AddCameraCommand(const double x, const double y, const double z);
    virtual ~AddCameraCommand() override = default;

    virtual void execute() override;
private:
    double x, y, z;
};

class RemoveCameraCommand: public CameraBaseCommand
{
public:
    RemoveCameraCommand() = delete;
    RemoveCameraCommand(const std::size_t &id);
    virtual ~RemoveCameraCommand() override = default;

    virtual void execute() override;
private:
    std::size_t id;
};

class MoveCameraCommand: public CameraBaseCommand
{
public:
    MoveCameraCommand() = delete;
    MoveCameraCommand(const double dx, const double dy, const std::size_t id);
    virtual ~MoveCameraCommand() override = default;

    virtual void execute() override;
private:
    double dx, dy;
    std::size_t id;
};

class SetCameraCommand: public CameraBaseCommand
{
public:
    SetCameraCommand() = delete;
    SetCameraCommand(const std::size_t id);
    virtual ~SetCameraCommand() override = default;

    virtual void execute() override;
private:
    std::size_t id;
};

class LoadCameraCommand: public CameraBaseCommand
{
public:
    LoadCameraCommand() = delete;
    LoadCameraCommand(const std::string filename);
    virtual ~LoadCameraCommand() override = default;

    virtual void execute() override;
private:
    std::string filename;
};

class SaveCameraCommand: public CameraBaseCommand
{
public:
    SaveCameraCommand() = delete;
    SaveCameraCommand(const std::string filename, std::size_t index);
    virtual ~SaveCameraCommand() override = default;

    virtual void execute() override;
private:
    std::string filename;
    std::size_t index;

};

#endif // CAMERACOMMAND_H
