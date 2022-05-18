#include <iostream>
#include <MyAlgorithm.hpp>

int main()
{
    int array_of_int[100];
    for(int i=0 ; i<100 ; i++)
    {
        array_of_int[i] = i*2;
    }
    std::cout<<myalgoritm::binary_search(array_of_int,100,120)<<std::endl;
    std::cout<<myalgoritm::binary_search(array_of_int,100,121)<<std::endl;

    char array_of_char[100];
    for(int i=0 ; i<100 ; i++)
    {
        array_of_char[i] = i;
    }
    std::cout<<myalgoritm::binary_search(array_of_char,100,(char)20)<<std::endl;

    std::string array_of_string[100];
    for(int i=0 ; i<100 ; i++)
    {
        array_of_string[i] = std::to_string((i*2));
    }
    std::cout<<myalgoritm::binary_search(array_of_string,100,std::string("121"))<<std::endl;
}