#ifndef IPROCESSOR_HPP
#define IPROCESSOR_HPP

#include <string>

class IProcessor{
public:
    virtual void processor(std::string link) = 0;
    virtual void dirProcessor(std::string link) = 0;
    virtual void fileProcessor(std::string link) = 0;
    virtual ~IProcessor() = default;
};

#endif