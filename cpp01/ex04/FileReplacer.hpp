#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP
#include <string>
#include <iostream>
#include <fstream>

class FileReplacer{
    private:
        FileReplacer();
        std::string _file;
        std::string _s1;
        std::string _s2;
        std::ifstream _inputFile;
        std::ofstream _outFile;
        
        bool _isOpenStream();
        void _closeAllStream();
        void _replaceAndWrite(std::string line);
        void _replaceAllAndWrite();
        bool _execute();
    public:
        ~FileReplacer();
        FileReplacer(const std::string &file,const std::string &s1, const std::string &s2);
};

#endif