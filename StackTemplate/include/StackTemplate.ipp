
template < class T>     
Stack<T>::Stack():LHead(nullptr),sizeofStack(0)
{};

template < class T>     
Stack<T>::~Stack()
{
    while (isEmpty() == false)
    {
        std::cout<<top()<<std::endl;
        this->pop();
    }
}

template < class T>     
void Stack<T>::push(T obj){
    LHead = new listT<T>(obj, LHead);
    sizeofStack++;
}
template < class T>     
void Stack<T>::pop()
{
        listT<T>* top = LHead->pNextObj;
        delete LHead;
        LHead = top;
        sizeofStack--;
}
template < class T>     
T Stack<T>::top()
{
    return this->LHead->Obj;
}
template < class T>     
bool Stack<T>::isEmpty(){
    return sizeofStack == 0;
}
template < class T>     
void Stack<T>::replaceTop(T t){
    pop();
    push(t);
}
template < class T>     
size_t Stack<T>::length(){
    size_t Length= 0; 
    for(listT<T>* top =LHead; top != nullptr ;top=top->pNextObj,Length++);
    return Length;
}
template < class T>     
void Stack<T>::insert_at_pos(T t,size_t pos){
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
template < class T>     
void Stack<T>::delete_at_pos(size_t pos){
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

