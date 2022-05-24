#ifndef TREE_TEMPLATE_H
#define TREE_TEMPLATE_H 
#include <iostream>
template <typename T>
struct nodeT{
    T Obj;
    nodeT* pLeft;
    nodeT* pRight;
    nodeT(T obj, nodeT* pleft,nodeT* pright){
        this->Obj = obj;
        this->pLeft = pleft;
        this->pRight = pright;
    }
};

template <typename T>
nodeT<T>* MakeTree(T obj, nodeT<T>* pleft,nodeT<T>* pright);
template <typename T>
bool isempty( nodeT<T>* bst);
template <typename T>
T root(nodeT<T>* bst);
template <typename T>
nodeT<T>* left(nodeT<T>* bst);
template <typename T>
nodeT<T>* right(nodeT<T>* bst);
template <typename T>
nodeT<T>* insert(T obj, nodeT<T>* bst);
template <typename T>
bool isIn(T v, nodeT<T>* bst) ;
template <typename T>
nodeT<T>* findIn(T v, nodeT<T>* bst) ;
template <typename T>
void inorder( nodeT<T>* bst) ;
#include "TreeTemplate.ipp"
#endif // !TREE_TEMPLATE_H