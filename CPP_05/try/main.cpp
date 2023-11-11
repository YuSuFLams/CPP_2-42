#include <iostream>
#include <stdlib.h>
#include <exception>

int main(int ac, char **s)
{
    try
    {
        if (atoi(s[2]) == 0)
            throw "No Bro";
        else if (atoi(s[2]) < 0)
            throw 123;
        else
            std::cout << "resault is: " << (atoi(s[1]) / atoi(s[2])) << std::endl;
    }
    catch(const char *e)
    {
        std::cerr << e << std::endl;
    }
    catch(int e)
    {
        std::cerr << e << std::endl;
    }
    std::cout << "Yey" << std::endl;
}