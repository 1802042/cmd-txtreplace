#pragma once

#include "../headers/IProcessor.hpp"

#include <string>
#include <iostream>


class Processor: public IProcessor{
public:
    Processor() = delete;
    Processor(std::string refLink, std::string searchKey, std::string replaceKey):m_refLink(std::move(refLink)), m_searchKey(std::move(searchKey)), m_replaceKey(std::move(replaceKey))
    {}
    ~Processor() = default;

    void processor() override;

private:
    void dirProcessor(const std::string& entryPath);
    void fileProcessor(const std::string& entryPath);
    std::string modifyString(const std::string& word);
private:
    std::string m_refLink;
    std::string m_searchKey;
    std::string m_replaceKey;
};
