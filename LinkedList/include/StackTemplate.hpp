#ifndef Stack_H
#define Stack_H 

#include <iostream>
#include <mutex>
template <typename T>
struct listT{
    T Obj;
    listT* pNextObj;
    listT(T obj, listT* pNext){
        this->Obj = obj;
        this->pNextObj = pNext;
    }
    bool operator < (listT const &obj) {
         return this->Obj <obj.Obj;
    }
    bool operator > (listT const &obj) {
         return this->Obj >obj.Obj;
    }
    bool operator = (listT const &obj) {
         return this->Obj =obj.Obj;
    }
};

template < class T> class Stack{
    listT<T>* LHead =nullptr;
    size_t sizeofStack =0;
    std::mutex m;
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
         std::unique_lock<std::mutex> lock(m);
         LHead = new listT<T>(obj, LHead);
         sizeofStack++;
     }
    void pop()
    {
         std::unique_lock<std::mutex> lock(m);
         listT<T>* top = LHead->pNextObj;
         delete LHead;
         LHead = top;
         sizeofStack--;
    }
    T top()
    {
       std::unique_lock<std::mutex> lock(m);
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
        std::unique_lock<std::mutex> lock(m);
        for(listT<T>* top =LHead; top != nullptr ;top=top->pNextObj,Length++);
        return Length;
    }
    void insertAtPos(T t,size_t pos){
        if(pos == 0)
        {
            push(t);
            return;
        } 
        size_t Length= 1;
        std::unique_lock<std::mutex> lock(m);
        listT<T> *itr =LHead;
        for(; itr != nullptr && Length!=pos ;itr=itr->pNextObj,Length++);
        
        if(itr!=nullptr){
            itr->pNextObj = new listT<T>(t,itr->pNextObj);
            sizeofStack++;
            }
        else
            std::cout<<"pos is greater than Stack Size"<<std::endl;
    }
    void deleteAtPos(size_t pos){
        if(pos == 0)
        {
            pop();
            return;
        } 
        size_t Length= 1; 
        std::unique_lock<std::mutex> lock(m);
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