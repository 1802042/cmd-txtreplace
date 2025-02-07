#pragma once
#include <memory>

#include "IProcessor.hpp"

namespace ProcessorFactory{
    std::unique_ptr<IProcessor> createProcessor (const std::string& refLink, const std::string& searchKey, const std::string& replaceKey);
}