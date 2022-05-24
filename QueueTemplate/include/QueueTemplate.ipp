
template < class T> 
Queue<T>::Queue():LHead(nullptr){};

template < class T> 
Queue<T>::~Queue()
{
    while (LHead != nullptr)
    {
        pop();
    }
    
}
template < class T>      
void Queue<T>::push(T obj){
    LHead = new listT<T>(obj, LHead);
}
template < class T> 
void Queue<T>::pop()
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
template < class T> 
T Queue<T>::top()
{
    return this->LHead->Obj;
}
template < class T> 
size_t Queue<T>::length(){
    size_t Length= 0; 
    for(listT<T>* itr =LHead; itr != nullptr ;itr=itr->pNextObj,Length++);
    return Length;
}


