#ifndef MYALGORITHM_HPP
#define MYALGORITHM_HPP
#include <cstddef>
namespace myalgoritm{

bool isprime(int n);
double factorial(int n);
template <typename T>
int binary_search(T arrayT[], int size_of_array, T t)
{

    size_t left=0,mid=0,right=size_of_array;
    while (left<right )
    {
        mid=(left +right)/2;

        if(t>arrayT[mid])
            left=mid+1;
        else
            right = mid;
    }
    return (arrayT[left] == t )? left : (int)-1;
}
}
#endif