#include "filecameraexporter.h"
#include "camera.h"
#include <fstream>

FileCameraExporter::FileCameraExporter()
{}

FileCameraExporter::FileCameraExporter(std::shared_ptr<std::ofstream> output)
    : file(std::move(output)) {}

void FileCameraExporter::save(std::shared_ptr<Object> object)
{
    std::shared_ptr<Camera> camera = std::dynamic_pointer_cast<Camera>(object);
    Point pos = camera->getPosition();
    *file << pos.get_x() << " " << pos.get_y() << " " << pos.get_z() << std::endl;
}

void FileCameraExporter::open(std::string filename)
{
    file = std::shared_ptr<std::ofstream>(new std::ofstream(filename));
//    if (!*file) throw exception
}

void FileCameraExporter::close()
{
    file->close();
}
