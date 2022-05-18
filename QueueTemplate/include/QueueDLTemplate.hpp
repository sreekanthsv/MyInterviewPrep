#ifndef QUEUE_DL_H
#define QUEUE_DL_H 

#include <iostream>
template <typename T>
struct listT{
    T Obj;
    listT* pNextObj;
    listT* pPrevObj;
    listT(T obj, listT* pNext,listT* pPrev){
        this->Obj = obj;
        this->pNextObj = pNext;
        this->pPrevObj = pPrev ;
    }
};

template < class T> class Queue{
    listT<T>* LHead =nullptr;
    listT<T>* LTail =nullptr;
public: 
     Queue():LTail(nullptr),LHead(nullptr){};

    ~Queue(){
        while (LHead != nullptr)
        {
            pop();
        }
        
    }
     
     void push(T obj){
         LHead = new listT<T>(obj, LHead,nullptr);
         if(LTail == nullptr)
        {
            LTail = LTail;
        }
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