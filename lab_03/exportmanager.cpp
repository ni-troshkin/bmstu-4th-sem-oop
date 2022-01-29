#include "exportmanager.h"

ExportManager::ExportManager(std::shared_ptr<BaseExporter> exporter)
    : exporter(std::move(exporter)) {}

void ExportManager::setExporter(const std::shared_ptr<BaseExporter> exporter)
{
    this->exporter = exporter;
}

void ExportManager::save(std::string source, std::shared_ptr<Object> object)
{
    exporter->open(source);
    exporter->save(object);
    exporter->close();
}
