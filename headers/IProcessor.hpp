#ifndef IPROCESSOR_HPP
#define IPROCESSOR_HPP

#include <string>

class IProcessor{
public:
    virtual void processor(std::string ref_link, std::string searchkey, std::string replaceKey) = 0;
    virtual void dirProcessor(std::string ref_link, std::string searchkey, std::string replaceKey) = 0;
    virtual void fileProcessor(std::string ref_link, std::string searchkey, std::string replaceKey) = 0;
    virtual ~IProcessor() = default;
};

#endif