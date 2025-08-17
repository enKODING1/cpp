#include "FileReplacer.hpp"

FileReplacer::FileReplacer()
{

}

FileReplacer::~FileReplacer()
{

}

FileReplacer::FileReplacer(const std::string &file, const std::string &s1, const std::string &s2)
    : _file(file), 
      _s1(s1), 
      _s2(s2),
      _inputFile(file.c_str()),
      _outFile((file + ".replace").c_str())
{
    _execute();
}

bool FileReplacer::_isOpenStream()
{
    if (_inputFile.is_open() && _outFile.is_open())
        return true;
    return false;
}

void FileReplacer::_closeAllStream()
{
    _inputFile.close();
    _outFile.close();
}

void FileReplacer::_replaceAndWrite(std::string line)
{
    std::size_t pos = 0;

    while((pos = line.find(_s1, pos)) != std::string::npos)
    {
        _replace(line, pos, _s1.length(), _s2);
        pos += _s2.length();
    }

    _outFile << line << std::endl;
}


void FileReplacer::_replaceAllAndWrite()
{
    std::string line;
    
    while(std::getline(_inputFile, line))
        _replaceAndWrite(line);
}

bool FileReplacer::_execute()
{
    if (!_isOpenStream())
    {
        std::cout << "can't open file!" << std::endl;
        return false;
    }

    _replaceAllAndWrite();
    _closeAllStream();
    return true;
}

void FileReplacer::_replace(std::string &str, std::size_t pos, std::size_t n, std::string &s)
{
    str.erase(pos, n);
    str.insert(pos, s);
}
