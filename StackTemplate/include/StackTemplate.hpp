#ifndef STACK_H
#define STACK_H 

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

template < class T> class Stack{
    listT<T>* LHead =nullptr;
    size_t sizeofStack =0;
public: 
     Stack();
    ~Stack();
     
    void push(T obj);
    void pop();
    T top();
    bool isEmpty();
    void replaceTop(T t);
    size_t length();
    void insert_at_pos(T t,size_t pos);
    void delete_at_pos(size_t pos);
};

#include "StackTemplate.ipp"
#endif // !Stack_H