#pragma once 

#include <string>

class IProcessor{
public:
    virtual void processor() = 0;
    virtual ~IProcessor() = default;
};
