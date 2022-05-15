#include <Observer.hpp>

int Observer::static_number_ = 0;
Subject::~Subject() {
  std::cout << "Goodbye, I was the Subject.\n";
}

/**
 * The subscription management methods.
 */
void Subject::Attach(IObserver *observer)  {
  list_observer_.push_back(observer);
}
void Subject::Detach(IObserver *observer)  {
  list_observer_.remove(observer);
}
void Subject::Notify()  {
  std::list<IObserver *>::iterator iterator = list_observer_.begin();
  HowManyObserver();
  while (iterator != list_observer_.end()) {
    (*iterator)->Update(message_);
    ++iterator;
  }
}

void Subject::CreateMessage(std::string message ) {
  this->message_ = message;
  Notify();
}
void Subject::HowManyObserver() {
  std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
}

/**
 * Usually, the subscription logic is only a fraction of what a Subject can
 * really do. Subjects commonly hold some important business logic, that
 * triggers a notification method whenever something important is about to
 * happen (or after it).
 */
void Subject::SomeBusinessLogic() {
  this->message_ = "change message message";
  Notify();
  std::cout << "I'm about to do some thing important\n";
}

Observer::Observer(Subject &subject) : subject_(subject) {
  this->subject_.Attach(this);
  std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
  this->number_ = Observer::static_number_;
}
Observer::~Observer() {
  std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void Observer::Update(const std::string &message_from_subject)  {
  message_from_subject_ = message_from_subject;
  PrintInfo();
}
void Observer::RemoveMeFromTheList() {
  subject_.Detach(this);
  std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
}
void Observer::PrintInfo() {
  std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
}