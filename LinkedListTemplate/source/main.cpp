#include "LinkedList.hpp"

int main()
{
    listT<int>*gHead =nullptr;
    add_node_1to4(&gHead);
    std::cout<<"print_all_in_list"<<std::endl;
    print_all_in_list(gHead);

    std::cout<<"reverse_the_list"<<std::endl;
    reverse_the_list(&gHead);
    std::cout<<"print_all_in_list"<<std::endl;
    print_all_in_list(gHead);

    std::cout<<"print_from_last"<<std::endl;
    print_from_last(gHead);

    listT<int> *list1=nullptr,*list2=nullptr;
    std::cout<<"split_Liked_List"<<std::endl;
    split_Linked_List(&gHead,&list1,&list2);
    std::cout<<"print_all_in_list1"<<std::endl;
    print_all_in_list(list1);
    std::cout<<"print_all_in_list2"<<std::endl;
    print_all_in_list(list2);
    delete_list(&list1);
    delete_list(&list2);
}