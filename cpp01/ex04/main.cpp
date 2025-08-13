#include <iostream>
#include <string>
#include <fstream>
#include "FileReplacer.hpp"

int main(int argc, char **argv)
{
    // <filename>.replace 형식으로 저장해야하는데 foobar.txt의 경우 .txt제거 후 replace로 저장할지 생각해보기
    if (argc != 4)
    {
        std::cout << "check arguments!!" << std::endl;
        return 0;
    }

    std::string file = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    FileReplacer replacer(file, s1, s2);
    // std::ifstream inputFile(argv[1]);
    // std::ofstream outFile("foobar.replace");
    // if(!inputFile.is_open())
    //     std::cout << "can't open file!" << std::endl;
    
    // std::string line;
    // while(std::getline(inputFile, line))
    // {
    //     std::cout << line << std::endl;
    //     std::size_t pos = 0;
        
    //     while((pos = line.find(target, pos)) != std::string::npos)
    //     {
    //         line.replace(pos, target.length(), replace);
    //         std::cout << "replaced string: " << line << std::endl;
    //         pos += replace.length();
    //     }
    //     outFile << line << std::endl;
    //     std::cout << std::endl;
    // }
    // inputFile.close();
    // outFile.close();
    return 0;
}