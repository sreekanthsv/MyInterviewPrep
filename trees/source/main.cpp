#include "TreeTemplate.hpp"

int main()
{
    nodeT<int>*gHead =nullptr;

    for(int i=0;i<50;i++)
    {
        gHead = insert(i*2,gHead);
    }
    std::cout<<"insert complete"<<std::endl;
    for(int i=0;i<50;i++)
    {
        std::cout<<i<<" "<<isIn(i,gHead)<<std::endl;
    }
}