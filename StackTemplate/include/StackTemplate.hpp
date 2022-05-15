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
     Stack():LHead(nullptr),sizeofStack(0){};

    ~Stack(){
        while (isEmpty() == false)
        {
            std::cout<<top()<<std::endl;
            this->pop();
        }
        
    }
     
     void push(T obj){
         LHead = new listT<T>(obj, LHead);
         sizeofStack++;
     }
    void pop()
    {
         listT<T>* top = LHead->pNextObj;
         delete LHead;
         LHead = top;
         sizeofStack--;
    }
    T top()
    {
       return this->LHead->Obj;
    }
    bool isEmpty(){
        return sizeofStack == 0;
    }
    void replaceTop(T t){
        pop();
        push(t);
    }
    size_t length(){
        size_t Length= 0; 
        for(listT<T>* top =LHead; top != nullptr ;top=top->pNextObj,Length++);
        return Length;
    }
    void insert_at_pos(T t,size_t pos){
        if(pos == 0)
        {
            push(t);
            return;
        } 
        size_t Length= 1;
        listT<T> *itr =LHead;
        for(; itr != nullptr && Length!=pos ;itr=itr->pNextObj,Length++);
        
        if(itr!=nullptr){
            itr->pNextObj = new listT<T>(t,itr->pNextObj);
            sizeofStack++;
            }
        else
            std::cout<<"pos is greater than Stack Size"<<std::endl;
    }
    void delete_at_pos(size_t pos){
        if(pos == 0)
        {
            pop();
            return;
        } 
        size_t Length= 1; 
        listT<T> *itr =LHead;
        for(; itr != nullptr && Length!=pos ;itr=itr->pNextObj,Length++);
        
        if(itr == nullptr)
        {
            std::cout<<"pos is greater than Stack Size"<<std::endl;
            return;
        }
        listT<T>* element =itr->pNextObj;
        
        itr->pNextObj = nullptr ;
        if (element!=nullptr)
        {
            itr->pNextObj =element->pNextObj;
            delete element;
            sizeofStack--;
        }     
           
    }
};


#endif // !Stack_H