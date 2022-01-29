#ifndef EXPORTMANAGER_H
#define EXPORTMANAGER_H

#include "basemanager.h"
#include "baseexporter.h"
#include "object.h"

class ExportManager: public BaseManager
{
public:
    ExportManager() = default;
    ExportManager(std::shared_ptr<BaseExporter> exporter);
    ExportManager(const ExportManager &manager) = delete;
    ExportManager& operator=(const ExportManager &manager) = delete;

    ~ExportManager() = default;
    void setExporter(const std::shared_ptr<BaseExporter> exporter);
    void save(std::string source, std::shared_ptr<Object> object);
private:
    std::shared_ptr<BaseExporter> exporter;
};
#endif // EXPORTMANAGER_H
