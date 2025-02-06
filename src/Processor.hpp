#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "../headers/IProcessor.hpp"

#include <string>
#include <iostream>


class Processor: public IProcessor{
public:
    void processor(std::string link) override;
    void dirProcessor(std::string link) override;
    void fileProcessor(std::string link) override;
};

#endif