#ifndef SUBJECT_H
#define SUBJECT_H
#include <QVariantMap>

class Observer;

class Subject {

protected:
  QList<Observer*> observers;

public:
  virtual void attach(Observer*) =0;
  virtual void detach(Observer*) =0;
  virtual void notifyObservers() =0;
  virtual ~Subject() = default;
};



#endif //SUBJECT_H
