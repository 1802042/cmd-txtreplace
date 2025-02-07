
#include "ProcessorFactory.hpp"
#include "Processor.hpp"

std::unique_ptr<IProcessor> ProcessorFactory::createProcessor (const std::string& refLink, const std::string& searchKey, const std::string& replaceKey)
{
    return std::make_unique<Processor>(refLink, searchKey, replaceKey);
}

