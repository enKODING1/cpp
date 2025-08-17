#include <iostream>
#include <string>
#include <fstream>
#include "FileReplacer.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "check arguments!!" << std::endl;
        return 0;
    }

    std::string file = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    FileReplacer replacer(file, s1, s2);
    return 0;
}