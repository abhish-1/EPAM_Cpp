/**
 * Observer Design Pattern
 *
 * Intent: Lets you define a subscription mechanism to notify multiple objects
 * about any events that happen to the object they're observing.
 *
 * Note that there's a lot of different terms with similar meaning associated
 * with this pattern. Just remember that the Subject is also called the
 * Publisher and the Observer is often called the Subscriber and vice versa.
 * Also the verbs "observe", "listen" or "track" usually mean the same thing.
 */

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

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */

class Subject : public ISubject {
    private:
    std::list<IObserver *> listSubscriber;
    std::string msg;

    public:
    virtual ~Subject() {
        std::cout << "Goodbye, I was the Subject.\n";
    }

  /**
   * The subscription management methods.
   */
  void Attach(IObserver *observer) override {
    listSubscriber.push_back(observer);
  }
  void Detach(IObserver *observer) override {
    listSubscriber.remove(observer);
  }
  void Notify() override {
    std::list<IObserver *>::iterator iterator = listSubscriber.begin();
    //HowManyObserver();
    while (iterator != listSubscriber.end()) {
      (*iterator)->Update(msg);
      ++iterator;
    }
  }

  void CreateMessage(std::string message = "Empty") {
    this->msg = message;
    Notify();
  }
//   void HowManyObserver() {
//     std::cout << "There are " << listSubscriber.size() << " observers in the list.\n";
//   }

  /**
   * Usually, the subscription logic is only a fraction of what a Subject can
   * really do. Subjects commonly hold some important business logic, that
   * triggers a notification method whenever something important is about to
   * happen (or after it).
   */
//   void SomeBusinessLogic() {
//     this->msg = "change message message";
//     Notify();
//     std::cout << "I'm about to do some thing important\n";
//   }

};

class Observer : public IObserver {
    private:
    std::string message_from_subject;
    Subject &subjectRef;
    // static int staticNumber;
    // int num;

    public:
    Observer(Subject &subject) : subjectRef(subject) {
        this->subjectRef.Attach(this);
        //std::cout << "Hi, I'm the Observer \"" << ++Observer::static_number_ << "\".\n";
        //this->number_ = Observer::static_number_;
    }
    virtual ~Observer() {
        std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
    }

    void Update(const std::string &message_from_subject) override {
        message_from_subject = message_from_subject;
        //PrintInfo();
    }
    void RemoveMeFromTheList() {
        subjectRef.Detach(this);
        //std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }
    // void PrintInfo() {
    //     std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    // }

};

int Observer::static_number_ = 0;

void ClientCode() {
  Subject *subject = new Subject;
  Observer *observer1 = new Observer(*subject);
  Observer *observer2 = new Observer(*subject);
  Observer *observer3 = new Observer(*subject);
  Observer *observer4;
  Observer *observer5;

  subject->CreateMessage("Hello World! :D");
  observer3->RemoveMeFromTheList();

  subject->CreateMessage("The weather is hot today! :p");
  observer4 = new Observer(*subject);

  observer2->RemoveMeFromTheList();
  observer5 = new Observer(*subject);

  subject->CreateMessage("My new car is great! ;)");
  observer5->RemoveMeFromTheList();

  observer4->RemoveMeFromTheList();
  observer1->RemoveMeFromTheList();

  delete observer5;
  delete observer4;
  delete observer3;
  delete observer2;
  delete observer1;
  delete subject;
}

int main() {
  ClientCode();
  return 0;
}