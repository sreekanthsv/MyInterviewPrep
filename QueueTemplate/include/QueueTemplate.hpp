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
    Queue();
    ~Queue();
    void push(T obj);
    void pop();
    T top();
    size_t length();
};

#include "QueueTemplate.ipp"
#endif // !Queue_H