#include "TreeTemplate.hpp"

int main()
{
    nodeT<int>*gHead =nullptr;

    for(int i=0;i<50;i++)
    {
        gHead = insert(i*2,gHead);
    }

    inorder(gHead);

    for(int i=0;i<50;i++)
    {
        if(isIn(i,gHead))
            std::cout<<(findIn(i,gHead)->Obj)<<std::endl;
    }
}