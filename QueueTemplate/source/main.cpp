#include <QueueTemplate.hpp>

int main()
{
    Queue<int> queue_of_int;

    queue_of_int.push(1);
    queue_of_int.push(2);
    queue_of_int.push(5);
    queue_of_int.push(3);
    queue_of_int.push(9);
    std::cout<< "length "<<queue_of_int.length()<<std::endl;
    
}