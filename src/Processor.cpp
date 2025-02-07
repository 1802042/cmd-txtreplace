#include "Processor.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void Processor::processor() {

    if (fs::is_directory(m_refLink))
    {
        dirProcessor(m_refLink);
    }
    else if (fs::is_regular_file(m_refLink))
    {
        fileProcessor(m_refLink);
    }
    else 
    {
        throw std::runtime_error("Invalid path: " + m_refLink);
    }
}

void Processor::dirProcessor(const std::string& refLink) {
    
    for (const auto& entry : fs::directory_iterator(refLink)) {
        
        std::string entryPath = entry.path().string();
        if (fs::is_regular_file(entry.status())) {
            fileProcessor(entryPath);
        } else if (fs::is_directory(entry.status())) {
            dirProcessor(entryPath);
        }
    }
}

std::string Processor::modifyString(const std::string& word)
{
    std::string kmpSeed = m_searchKey + "$" + word;

    int seedLength = kmpSeed.size();
    int failureTable[seedLength];
    failureTable[0] = 0;

    for (int i = 1; i < seedLength; ++i)
    {
        int commonSuffix = failureTable[i - 1];
        while (commonSuffix > 0 && kmpSeed[commonSuffix] != kmpSeed[i])
            commonSuffix = failureTable[commonSuffix - 1];
        if (kmpSeed[commonSuffix] == kmpSeed[i])
            ++commonSuffix;
        failureTable[i] = commonSuffix;
    }

    int wordLen = word.size();
    int skeyLen = m_searchKey.size();

    std::string resWord = "";
    for (int i = 0; i < wordLen; )
    {
        if (failureTable[i + skeyLen + 1] == skeyLen)
        {
            for (int j = 0; j + 1 < skeyLen; ++j) 
            {
                resWord.pop_back();
            }
            resWord += m_replaceKey;
            for (int j = 0; j + 1 < skeyLen && j + i + 1 < wordLen; ++j)
            {
                resWord += word[i + j + 1];
            }
            i += skeyLen;
        }
        else 
        {
            resWord += word[i];
            ++i;
        }
    }
    return resWord;
}

void Processor::fileProcessor(const std::string& entryPath) {

    std::ifstream file(entryPath);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + entryPath);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    std::string word;
    std::string updatedFileContent = "";

    while (buffer >> word)
    {
        word = modifyString(word);
        if ((uint)updatedFileContent.size() != 0)
            updatedFileContent += " ";
        updatedFileContent += word;
    }

    std::ofstream updatedFile(entryPath);
    updatedFile << updatedFileContent;
    updatedFile.close();
}
