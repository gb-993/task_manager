#include "goal.h"
#include <QDebug>

#include "category.h"

Goal::Goal(QString d,  int ma) : description(d),  max(ma) {
    category = nullptr;
    min = 0;
    counter = 0;
}

QString Goal::getDescription() const { return description; }
QString Goal::getCategory() const { return category; }
int Goal::getCounter() const { return counter; }
int Goal::getMax() const { return max; }
int Goal::getMin() const { return min; }

void Goal::setDescription(QString s) {
    description = s;
    //notifyObservers();
}

void Goal::setCategory(QString s) {
    category = s;
    //notifyObservers(); /* non dovrebbe essere modificata una volta attribuita */
}


void Goal::setMax(int n) {
    max = n;
    //notifyObservers();
}

void Goal::print() const{
    qDebug() << "Description: " << getDescription() <<" Category: "<<getCategory()<<" Total: "<< max << " Counter: " << getCounter();
}

void Goal::addOne() {
    if (counter < max) {
        counter++;
        //notifyObservers();
    } else {
        qDebug() << "limite max superato";
    }
}

void Goal::removeOne() {
    if (counter > min) {
        counter--;
        //notifyObservers();
    } else {
        qDebug() << "limite min superato";
    }
}

void Goal::attach(Observer* observer) {
    observers.push_back(observer);
}

void Goal::detach(Observer* observer) {
    observers.removeAll(observer);
}

void Goal::notifyObservers() {
    for (int i = 0; i < observers.size(); i++) {
        observers[i]->update();
    }
}

Goal::~Goal() {
    observers.clear();
}
