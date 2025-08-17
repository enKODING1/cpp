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
      _s2(s2)
{
    
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

bool FileReplacer::run()
{
    _inputFile.open(_file.c_str());
    if (!_inputFile.is_open())
    {
        std::cerr << "Error: Input file cannot be opened." << std::endl;
        return false;
    }

    _outFile.open((_file + ".replace").c_str());
    if (!_outFile.is_open())
    {
        std::cerr << "Error: Output file cannot be created." << std::endl;
        _inputFile.close();
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
