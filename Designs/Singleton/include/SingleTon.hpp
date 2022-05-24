#ifndef SINGLETON_TEMPLATE_H
#define SINGLETON_TEMPLATE_H
#include "mutex"
class SingleTon{


  private :
    SingleTon();
    SingleTon(const SingleTon& obj);
    static SingleTon* pSingleTon;
    static std::mutex oncelock;
    std::string  value ;
  public : 

  static SingleTon* getInstance();
  std::string getValue()
  {
    return value;
  }
  void setValue(std::string val)
  {
     value = val;
  }

};

#endif