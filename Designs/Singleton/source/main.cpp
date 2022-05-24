#include <SingleTon.hpp>
#include <iostream>
int main()
{
  SingleTon* pObj = SingleTon::getInstance();

  pObj->setValue("what is this");

  SingleTon* pObj2 = SingleTon::getInstance();

  std::cout<<pObj2->getValue()<<std::endl;

  SingleTon* pObj3 = SingleTon::getInstance();

  pObj3->setValue("I am third");
  std::cout<<pObj->getValue()<<std::endl;

}