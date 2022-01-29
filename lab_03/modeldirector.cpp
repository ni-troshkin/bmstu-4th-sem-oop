#include "modeldirector.h"
#include "filemodelloader.h"
#include <iostream>

ModelDirector::ModelDirector()
{
    loader = std::shared_ptr<FileModelLoader>(new FileModelLoader());
}

ModelDirector::ModelDirector(std::shared_ptr<BaseModelLoader> loader, std::shared_ptr<ModelBuilder> builder)
    : loader(std::move(loader)), builder(std::move(builder)) {}

std::shared_ptr<Object> ModelDirector::build(std::string source)
{
    loader->open(source);

    builder->reset();
    double x, y, z;
    x = loader->loadCoordinate();
    y = loader->loadCoordinate();
    z = loader->loadCoordinate();
    builder->buildCenter(x, y, z);

    std::size_t points_count, edges_count;
    std::size_t from, to;

    points_count = loader->loadSize();
    std::cout << points_count << " points to load" << std::endl;

    for (std::size_t i = 0; i < points_count; i++)
    {
        x = loader->loadCoordinate();
        y = loader->loadCoordinate();
        z = loader->loadCoordinate();
        builder->buildPoint(x, y, z);
    }

    edges_count = loader->loadSize();

    for (std::size_t i = 0; i < edges_count; i++)
    {
        from = loader->loadIndex(edges_count - 1);
        to = loader->loadIndex(edges_count - 1);
        builder->buildEdge(from, to);
    }

    std::shared_ptr<Object> model = builder->get();
    loader->close();

    return model;
}
