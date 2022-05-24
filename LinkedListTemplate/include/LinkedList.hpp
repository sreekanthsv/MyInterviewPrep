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
void push(listT<T>**LHead ,  T obj);
    
template < typename T>
void pop(listT<T>**LHead );
template < typename T>
T top(listT<T>**LHead);
template < typename T>
bool isEmpty(listT<T>**LHead);
template < typename T>
size_t length(listT<T>*LHead);
template < typename T>
void reverse_the_list(listT<T>** newHead);
template < typename T>
void add_node_1to4(listT<T>** newHead);
template < typename T>
void print_all_in_list(listT<T>* LHead);
template < typename T>
void print_from_last(listT<T>* LHead);
template < typename T>
void split_Linked_List(listT<T>** LHead,listT<T>** list1,listT<T>** list2);
template < typename T>
void delete_list(listT<T>** LHead);
#include "LinkedList.ipp"
#endif // !LinkedList_H