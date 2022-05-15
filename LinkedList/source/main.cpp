#include <iostream>
#include <LinkedList.hpp>
#include <thread>
#if 0
void savetolist(LinkedList<int>& listofint,int x){
    listofint.push(x);
    listofint.push(1*x);
    listofint.push(2*x);
    listofint.push(5*x);
    listofint.push(3*x);
    listofint.push(9*x);
}
#endif
int main()
{
 #if 0

    for(int i=0;i<100;i++)
    {
    LinkedList<int> listofint;

    std::thread Thread1(savetolist,std::ref(listofint), 1);
    std::thread Thread2(savetolist,std::ref(listofint),58);
    std::thread Thread3(savetolist,std::ref(listofint),88); 
    std::thread Thread4(savetolist,std::ref(listofint),99); 
    std::thread Thread5(savetolist,std::ref(listofint),100);
    listofint.push(1);
    listofint.push(2);
    listofint.push(5);
    listofint.push(3);
    listofint.push(9);
    listofint.insertAtPos(54,0);
    listofint.insertAtPos(444444,1);
    listofint.deleteAtPos(2);

    Thread1.join();
    Thread2.join();
    Thread3.join();
    Thread4.join();
    Thread5.join();
  
    listofint.reverse();

    std::cout<< "length "<<listofint.length()<<std::endl;
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(2000ms);
    }
#endif
    listT<int>*gHead =nullptr, *list1=nullptr,*list2=nullptr;
    addNode1to3(&gHead);
    printall(gHead);
    reverse(&gHead);
    printall(gHead);
    printreverse(gHead);
    splitLikedList(&gHead,&list1,&list2);
    printall(list1);
    printall(list2);
}