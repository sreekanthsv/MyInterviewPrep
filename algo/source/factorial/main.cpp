#include <iostream>
#include <MyAlgorithm.hpp>

int main()
{
    for(int i=0 ; i<100 ; i++)
    {
        std::cout<<i <<" "<<myalgoritm::factorial(i)<<std::endl;
    }
}