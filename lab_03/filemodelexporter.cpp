#include "filemodelexporter.h"
#include <fstream>
#include "model.h"

FileModelExporter::FileModelExporter()
{}

FileModelExporter::FileModelExporter(std::shared_ptr<std::ofstream> output)
    : file(std::move(output)) {}

void FileModelExporter::save(std::shared_ptr<Object> object)
{
    std::shared_ptr<ModelImplementation> imp = std::dynamic_pointer_cast<Model>(object)->getImplementation();

    Point center = imp->getCenter();
    *file << center.get_x() << " " << center.get_y() << " " << center.get_z() << std::endl;

    std::vector<Point> points = imp->getPoints();
    *file << points.size() << std::endl;

    for (auto point: points)
        *file << point.get_x() << " " << point.get_y() << " " << point.get_z() << std::endl;

    std::vector<Edge> edges = imp->getEdges();
    *file << edges.size() << std::endl;

    for (auto edge: edges)
        *file << edge.getFrom() << " " << edge.getTo() << std::endl;
}

void FileModelExporter::open(std::string filename)
{
    file = std::shared_ptr<std::ofstream>(new std::ofstream(filename));
//    if (!*file) throw exception
}

void FileModelExporter::close()
{
    file->close();
}
