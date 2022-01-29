#ifndef FILEMODELLOADER_H
#define FILEMODELLOADER_H

#include "basemodelloader.h"
#include "modelbuilder.h"

class FileModelLoader: public BaseModelLoader
{
public:
    FileModelLoader();
    explicit FileModelLoader(std::shared_ptr<std::ifstream> input);
    virtual ~FileModelLoader() override = default;

//    virtual std::shared_ptr<Object> load() override;
    virtual void open(std::string filename) override;
    virtual void close() override;

    virtual std::size_t loadIndex(std::size_t max_index) override;
    virtual double loadCoordinate() override;
    virtual std::size_t loadSize() override;

//    virtual void save(std::shared_ptr<Object>) override;
private:
    std::shared_ptr<std::ifstream> file;
    std::shared_ptr<ModelBuilder> builder;
};

#endif // FILEMODELLOADER_H
