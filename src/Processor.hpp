#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include "../headers/IProcessor.hpp"

#include <string>
#include <iostream>


class Processor: public IProcessor{
public:
    void processor(std::string ref_link, std::string searchKey, std::string replaceKey) override;
    void dirProcessor(std::string ref_link, std::string searchKey, std::string replaceKey) override;
    void fileProcessor(std::string ref_link, std::string searchKey, std::string replaceKey) override;
    std::string modifyString(std::string word, std::string searchKey, std::string replaceKey);
};

#endif