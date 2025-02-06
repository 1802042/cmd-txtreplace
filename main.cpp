#pragma once
#include "src/Processor.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "<Welcome to CMD-TEXTREPLACE, to know usage details see details in github>" << std::endl;
        return 1;
    }
    if (argc != 4 ) {
        std::cerr << "<Bad argument format>" << std::endl;
        return 1;
    }

    
    std::string ref_link = argv[1];
    std::string searchKey = argv[2];
    std::string replaceKey = argv[3];

    Processor cmd;
    cmd.processor(ref_link, searchKey, replaceKey);

    return 0;
}


