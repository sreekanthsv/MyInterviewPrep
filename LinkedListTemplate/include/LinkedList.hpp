#ifndef LINKEDLIST_H
#define LINKEDLIST_H 
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

template < typename T>
void push(listT<T>**LHead ,  T obj){
    *LHead = new listT<T>(obj, *LHead);
}
    
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
void reverse_the_list(listT<T>** newHead)
{
    if(*newHead == nullptr)
        return;
    listT<T> *first =*newHead,*rest=first->pNextObj;
    if(rest==nullptr)
        return;

    reverse_the_list(&rest);
    first->pNextObj->pNextObj = first;
    first->pNextObj = nullptr;
    *newHead = rest;
}

template < typename T>
void add_node_1to4(listT<T>** newHead)
{
    push(newHead,1);
    push(newHead,2);
    push(newHead,3);
    push(newHead,4);
    std::cout<<"Nodes Added"<<std::endl;
}
template < typename T>
void print_all_in_list(listT<T>* LHead)
{
    if(LHead == nullptr)
        return;
    std::cout<<LHead->Obj<<std::endl;
    print_all_in_list(LHead->pNextObj); 
}
template < typename T>
void print_from_last(listT<T>* LHead)
{
    if(LHead == nullptr)
        return;
    print_from_last(LHead->pNextObj);
    std::cout<<LHead->Obj<<std::endl;
}
template < typename T>
void split_Linked_List(listT<T>** LHead,listT<T>** list1,listT<T>** list2)
{
    if(*LHead == nullptr)
        return;
    push(list1, top(LHead));pop(LHead);
    if(*LHead == nullptr)
        return;
    push(list2,top(LHead));pop(LHead);
    split_Linked_List(LHead,list1,list2);
}
template < typename T>
void delete_list(listT<T>** LHead){
    if(*LHead == nullptr)
        return;
    pop(LHead);
    delete_list(LHead);
}
#endif // !LinkedList_H