#ifndef QUEUE_H
#define QUEUE_H 

#include <iostream>
template <typename T>
struct listT{
    T Obj;
    listT* pNextObj;
    listT(T obj, listT* pNext){
        this->Obj = obj;
        this->pNextObj = pNext;
    }
};

template < class T> class Queue{
    listT<T>* LHead =nullptr;
public: 
     Queue():LHead(nullptr){};

    ~Queue(){
        while (LHead != nullptr)
        {
            pop();
        }
        
    }
     
     void push(T obj){
         LHead = new listT<T>(obj, LHead);
     }
    void pop()
    {
        if(LHead== nullptr)
            return;
        if(LHead->pNextObj== nullptr)
        {
            std::cout<<LHead->Obj<<std::endl;
            delete LHead;
            LHead = nullptr;
            return;
        }
        
        listT<T> *itr = LHead;
        while (itr->pNextObj->pNextObj != nullptr)
        {
            itr=itr->pNextObj;
        }
        std::cout<<itr->pNextObj->Obj<<std::endl;
        delete itr->pNextObj;
        itr->pNextObj = nullptr;
    }
    T top()
    {
       return this->LHead->Obj;
    }
    size_t length(){
        size_t Length= 0; 
        for(listT<T>* itr =LHead; itr != nullptr ;itr=itr->pNextObj,Length++);
        return Length;
    }
};


#endif // !Queue_H