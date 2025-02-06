#include "Processor.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void Processor::processor(std::string ref_link, std::string searchKey, std::string replaceKey) {

    if (fs::is_directory(ref_link))
    {
        dirProcessor(ref_link, searchKey, replaceKey);
    }
    else if (fs::is_regular_file(ref_link))
    {
        fileProcessor(ref_link, searchKey, replaceKey);
    }
    else 
    {
        throw std::runtime_error("Invalid path: " + ref_link);
    }
}

void Processor::dirProcessor(std::string ref_link, std::string searchKey, std::string replaceKey) {

    for (const auto& entry : fs::directory_iterator(ref_link)) {
        std::string entryPath = entry.path().string();
        if (fs::is_regular_file(entry.status())) {
            fileProcessor(entryPath, searchKey, replaceKey);
        } else if (fs::is_directory(entry.status())) {
            dirProcessor(entryPath, searchKey, replaceKey);
        }
    }
    
}

std::string Processor::modifyString(std::string word, std::string searchKey, std::string replaceKey)
{
    std::string kmpSeed = searchKey + "$" + word;

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
    int skeyLen = searchKey.size();

    std::string resWord = "";
    for (int i = 0; i < wordLen; )
    {
        if (failureTable[i + skeyLen + 1] == skeyLen)
        {
            for (int j = 0; j + 1 < skeyLen; ++j) 
            {
                resWord.pop_back();
            }
            resWord += replaceKey;
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

void Processor::fileProcessor(std::string ref_link, std::string searchKey, std::string replaceKey) {
    
    std::ifstream file(ref_link);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + ref_link);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    std::string word;
    std::string updatedFileContent = "";

    while (buffer >> word)
    {
        word = modifyString(word, searchKey, replaceKey);
        if ((uint)updatedFileContent.size() != 0)
            updatedFileContent += " ";
        updatedFileContent += word;
    }

    std::ofstream updatedFile(ref_link);
    updatedFile << updatedFileContent;
    updatedFile.close();
}
