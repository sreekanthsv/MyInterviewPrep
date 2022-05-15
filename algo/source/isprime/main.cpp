#include <iostream>
#include <MyAlgorithm.hpp>

int main()
{
    for(int i=0 ; i<100 ; i++)
    {
        if(myalgoritm::isprime(i))
            std::cout<<i <<" is Prime"<<std::endl;
    }
}