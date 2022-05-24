#include <SingleTon.hpp>


SingleTon* SingleTon::pSingleTon=nullptr;
std::mutex SingleTon::oncelock;
SingleTon::SingleTon(){
}

SingleTon* SingleTon::getInstance(){

  oncelock.lock();
  if(pSingleTon == nullptr )
    SingleTon::pSingleTon = new SingleTon();
  oncelock.unlock();
  return pSingleTon;
}