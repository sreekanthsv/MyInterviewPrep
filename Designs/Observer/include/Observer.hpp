#ifndef OBSERVER_TEMPLATE_H
#define OBSERVER_TEMPLATE_H
#include <iostream>
#include <list>
#include <string>

class IObserver {
 public:
  virtual ~IObserver(){};
  virtual void Update(const std::string &message_from_subject) = 0;
};

class ISubject {
 public:
  virtual ~ISubject(){};
  virtual void Attach(IObserver *observer) = 0;
  virtual void Detach(IObserver *observer) = 0;
  virtual void Notify() = 0;
};

class Subject : public ISubject {
 public:
  virtual ~Subject();

  void Attach(IObserver *observer) override ;
  void Detach(IObserver *observer) override;
  void Notify() override ;

  void CreateMessage(std::string message = "Empty");
  void HowManyObserver();
  void SomeBusinessLogic();

 private:
  std::list<IObserver *> list_observer_;
  std::string message_;
};

class Observer : public IObserver {
 public:
  Observer(Subject &subject) ;
  virtual ~Observer();

  void Update(const std::string &message_from_subject) override;
  void RemoveMeFromTheList() ;
  void PrintInfo();

 private:
  std::string message_from_subject_;
  Subject &subject_;
  static int static_number_;
  int number_;
};


#endif