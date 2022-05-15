#include <MyAlgorithm.hpp>
namespace myalgoritm{
bool isprime(int n)
{
    if(n<=1)
        return false;
    if(n<=3)
        return true;
    
    if( (n%2 == 0) || (n%3==0))
        return false;
    // all prime number fall under sequence 6n-1 6n+1

    for(int i=5 ; i*i <=n; i+=6)
        if((n%i == 0) || (n%(i+2)==0))
            return false;
    return true;
}
}
