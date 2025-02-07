
#include <gtest/gtest.h>
#include <fstream>

#include "ProcessorFactory.hpp"

bool compareFiles() {
    std::ifstream file1("/home/rony/Documents/Dev/cmd-txtreplace/docs/input.txt", std::ios::binary);

    std::ifstream file2("/home/rony/Documents/Dev/cmd-txtreplace/docs/expected.txt", std::ios::binary);

    std::string line1, line2;
    while (std::getline(file1, line1) && std::getline(file2, line2)) {
        if (line1 != line2) {
            return false;
        }
    }

    return file1.eof() && file2.eof();
}

TEST(ProcessorTest, outputFileTest)
{
    std::ifstream sourceFile("/home/rony/Documents/Dev/cmd-txtreplace/docs/original.txt", std::ios::binary);
    std::ofstream destinationFile("/home/rony/Documents/Dev/cmd-txtreplace/docs/input.txt", std::ios::binary);

    destinationFile << sourceFile.rdbuf();

    sourceFile.close();
    destinationFile.close();

    
    std::string ref_link = "/home/rony/Documents/Dev/cmd-txtreplace/docs/input.txt";
    std::string searchKey = "to";
    std::string replaceKey = "TO";

    std::unique_ptr<IProcessor> cmd = ProcessorFactory::createProcessor (ref_link, searchKey, replaceKey);
    cmd->processor();
    bool res = compareFiles();
    EXPECT_EQ(res, true) << res << "--------------------------------\n";
}