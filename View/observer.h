//
// Created by gb on 11/12/24.
//

#ifndef OBSERVER_H
#define OBSERVER_H

#include <QVariantMap>

class Observer {
public:
  virtual void update() = 0;
  virtual ~Observer() = default;
};



#endif //OBSERVER_H
