#include "filemodelloader.h"
#include <iostream>
#include <fstream>

FileModelLoader::FileModelLoader()
{
    builder = std::shared_ptr<ModelBuilder>(new ModelBuilder());
}

FileModelLoader::FileModelLoader(std::shared_ptr<std::ifstream> input)
    : file(std::move(input))
{
    builder = std::shared_ptr<ModelBuilder>(new ModelBuilder());
}

void FileModelLoader::open(std::string filename)
{
    file = std::shared_ptr<std::ifstream>(new std::ifstream(filename));
}

void FileModelLoader::close()
{
    file->close();
}

std::size_t FileModelLoader::loadIndex(std::size_t max_index)
{
    std::size_t index;
    *file >> index;
    if (index > max_index)
        return max_index;
    return index;
}

double FileModelLoader::loadCoordinate()
{
    double coord;
    *file >> coord;
    return coord;
}

std::size_t FileModelLoader::loadSize()
{
    std::size_t size;
    *file >> size;
    return size;
}

























//std::shared_ptr<Object> FileModelLoader::load()
//{
//    builder->reset();
//    double x, y, z;
//    std::size_t points_count, edges_count;
//    std::size_t from, to;

//    *file >> x >> y >> z;
//    builder->buildCenter(x, y, z);

//    *file >> points_count;
//    std::cout << points_count << " points to load" << std::endl;
////    std::vector<Point> points;
//    for (std::size_t i = 0; i < points_count; i++)
//    {
//        *file >> x >> y >> z;
//        builder->buildPoint(x, y, z);
////        points.push_back(Point(x, y, z));
//    }

////    builder->buildPoints(points);

//    *file >> edges_count;
////    std::vector<Edge> edges;
//    for (std::size_t i = 0; i < edges_count; i++)
//    {
//        *file >> from >> to;
//        builder->buildEdge(from, to);
////        edges.push_back(Edge(from, to));
//    }
////    builder->buildEdges(edges);

//    return builder->get();
//}

//void FileModelLoader::save(std::shared_ptr<Object> model)
//{
//    ModelImplementation imp = model.getImplementation();

//    Point center = imp.getCenter();
//    *file << center.get_x() << center.get_y() << center.get_z();

//    std::vector<std::shared_ptr<Point>> points = imp.getPoints();
//    *file << points.size() << std::endl;
//    for (auto point: points)
//        *file << point.get_x() << " " << point.get_y() << " " << point.get_z() << std::endl;

//    std::vector<std::shared_ptr<Edge>> edges = imp.getEdges();
//    *file << edges.size() << std::endl;
//    for (auto edge: edges)
//        *file << edge.getFrom() << " " << edge.getTo() << std::endl;
//}
