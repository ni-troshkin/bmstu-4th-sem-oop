#include "filecameraloader.h"
#include <fstream>

FileCameraLoader::FileCameraLoader()
{
    builder = std::shared_ptr<CameraBuilder>(new CameraBuilder());
}

FileCameraLoader::FileCameraLoader(std::shared_ptr<std::ifstream> input)
    : file(std::move(input))
{
    builder = std::shared_ptr<CameraBuilder>(new CameraBuilder());
}

//std::shared_ptr<Object> FileCameraLoader::load()
//{
//    builder->reset();
//    double x, y, z;
//    *file >> x >> y >> z;
//    builder->buildPosition(x, y, z);
//    return builder->get();
//}

void FileCameraLoader::open(std::string filename)
{
    file = std::shared_ptr<std::ifstream>(new std::ifstream(filename));
//    if (!*file) throw exception
}

void FileCameraLoader::close()
{
    file->close();
}

std::size_t FileCameraLoader::loadIndex(std::size_t max_index)
{
    std::size_t index;
    *file >> index;
    if (index > max_index)
        return max_index;
    return index;
}

double FileCameraLoader::loadCoordinate()
{
    double coord;
    *file >> coord;
    return coord;
}

std::size_t FileCameraLoader::loadSize()
{
    std::size_t size;
    *file >> size;
    return size;
}

//void FileCameraLoader::save(std::shared_ptr<Object> camera)
//{
//    Point position = camera->getPosition();
//    *file << position.get_x() << position.get_y() << position.get_z();
//}
