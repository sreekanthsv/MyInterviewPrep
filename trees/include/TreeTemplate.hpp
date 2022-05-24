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
nodeT<T>* MakeTree(T obj, nodeT<T>* pleft,nodeT<T>* pright)
{
    return (new nodeT<T>(obj, pleft, pright));
}


template <typename T>
bool isempty( nodeT<T>* bst)
{
    return bst == nullptr ;    
}
template <typename T>
T root(nodeT<T>* bst)
{
    return bst->Obj;
}
template <typename T>
nodeT<T>* left(nodeT<T>* bst)
{
    return bst->pLeft;
}
template <typename T>
nodeT<T>* right(nodeT<T>* bst)
{
    return bst->pRight ;
}

template <typename T>
nodeT<T>* insert(T obj, nodeT<T>* bst)
{
    if(isempty(bst))     
        return new nodeT<T>(obj,nullptr,nullptr);
    else if ( obj < bst->Obj)
        return MakeTree(root(bst),insert(obj,left(bst)),right(bst));
    else if ( obj > bst->Obj)
        return MakeTree(root(bst),left(bst),insert(obj,right(bst)));
}
template <typename T>
bool isIn(T v, nodeT<T>* bst) {
    if ( isempty(bst) )
        return false;
    else if ( v == root(bst) )
        return true;
    else if ( v < root(bst) )
        return isIn(v, left(bst));
    else
        return isIn(v, right(bst));
}
template <typename T>
nodeT<T>* findIn(T v, nodeT<T>* bst) {
    if ( isempty(bst) )
        return nullptr;
    else if ( v == root(bst) )
        return bst;
    else if ( v < root(bst) )
        return findIn(v, left(bst));
    else
        return findIn(v, right(bst));
}

template <typename T>
void inorder( nodeT<T>* bst) {
    if ( isempty(bst) )
        return ;
    
    inorder(bst->pLeft);
    std::cout<<bst->Obj<<std::endl;
    inorder(bst->pRight);
}

#endif // !TREE_TEMPLATE_H