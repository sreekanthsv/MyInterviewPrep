#include <StackTemplate.hpp>

int main()
{
    Stack<int> listofint;

    listofint.push(1);
    listofint.push(2);
    listofint.push(5);
    listofint.push(3);
    listofint.push(9);
    listofint.insert_at_pos(54,0);
    listofint.insert_at_pos(444444,1);
    listofint.delete_at_pos(2);
    std::cout<< "length "<<listofint.length()<<std::endl;
    
}