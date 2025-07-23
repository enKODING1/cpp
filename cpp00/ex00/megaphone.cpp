#include <iostream>
#include <cctype>

void print_string_to_uppercase(char *str)
{
     for (int i = 0; str[i] != '\0'; ++i)
     {
        if (std::isalpha(str[i]))
            std::cout << (char)std::toupper(str[i]);
        else
            std::cout << (char)str[i];
     }
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    for (int i = 1; argv[i] != NULL; ++i)
        print_string_to_uppercase(argv[i]);
    std::cout << std::endl;
    
    return 0;
}