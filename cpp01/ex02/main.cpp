#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *strPtr = &str;
    std::string &strRef = str;

    std::cout << "adress of str: " << &str << "\nvalue: " << str << std::endl << std::endl;
    std::cout << "adress of ptr: " << &strPtr << "\nvalue: " << *strPtr << std::endl << std::endl;
    std::cout << "adress of ref: " << &strRef << "\nvalue: " << strRef << std::endl;


    return 0;
};