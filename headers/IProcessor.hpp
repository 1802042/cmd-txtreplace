#ifndef IPROCESSOR_HPP
#define IPROCESSOR_HPP

class IProcessor{
public:
    virtual void Processor() = 0;
    virtual void dirProcessor() = 0;
    virtual void fileProcessor() = 0;
    virtual ~IProcessor() = default;
};

#endif