#ifndef LINKEDLIST_H
#define LINKEDLIST_H 
#include "StackTemplate.hpp"
#include <iostream>
#include <mutex>
// template <typename T>
// struct listT{
//     T Obj;
//     listT* pNextObj;
//     listT(T obj, listT* pNext){
//         this->Obj = obj;
//         this->pNextObj = pNext;
//     }
//     bool operator < (listT const &obj) {
//          return this->Obj <obj.Obj;
//     }
//     bool operator > (listT const &obj) {
//          return this->Obj >obj.Obj;
//     }
//     bool operator = (listT const &obj) {
//          return this->Obj =obj.Obj;
//     }
// };

template < typename T>
void push(listT<T>**LHead ,  T obj){
    *LHead = new listT<T>(obj, *LHead);
}


//     ~LinkedList(){
//         while (isEmpty() == false)
//         {
//             std::cout<<top()<<std::endl;
//             this->pop();
//         }
        
//     }
     
template < typename T>
void pop(listT<T>**LHead )
{
    listT<T>* top = (*LHead)->pNextObj;
    delete *LHead;
    *LHead = top;
}
template < typename T>
T top(listT<T>**LHead)
{
    return (*LHead)->Obj;
}
template < typename T>
bool isEmpty(listT<T>**LHead)
{
    return *LHead == nullptr;
}
template < typename T>
size_t length(listT<T>*LHead)
{
    size_t Length= 0; 
    for(listT<T>* top =*LHead; top != nullptr ;top=top->pNextObj,Length++);
    return Length;
}
template < typename T>
void reverse(listT<T>** newHead)
{
    if(*newHead == nullptr)
        return;
    listT<T> *first =*newHead,*rest=first->pNextObj;
    if(rest==nullptr)
        return;

    reverse(&rest);
    first->pNextObj->pNextObj = first;
    first->pNextObj = nullptr;
    *newHead = rest;
}

template < typename T>
void addNode1to3(listT<T>** newHead)
{
    push(newHead,1);
    push(newHead,2);
    push(newHead,3);
    push(newHead,4);
}
template < typename T>
void printall(listT<T>* LHead)
{
    if(LHead == nullptr)
        return;
    std::cout<<LHead->Obj<<std::endl;
    printreverse(LHead->pNextObj);    
}
template < typename T>
void printreverse(listT<T>* LHead)
{
    if(LHead == nullptr)
        return;
    printreverse(LHead->pNextObj);
    std::cout<<LHead->Obj<<std::endl;
}
template < typename T>
void splitLikedList(listT<T>** LHead,listT<T>** list1,listT<T>** list2)
{
    if(*LHead == nullptr)
        return;
    push(list1, top(LHead));pop(LHead);
    if(*LHead == nullptr)
        return;
    push(list2,top(LHead));pop(LHead);
    splitLikedList(LHead,list1,list2);
}
#endif // !LinkedList_H