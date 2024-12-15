#include "category.h"


Category::Category(QString d ) : description(d) {
    completedTask = 0;
    totalTask = 0;
}

QString Category::getDescription() const{
    return description;
}

int Category::getTotalTask() const{
    return totalTask;
}

int Category::getCompletedTask() const {
    return completedTask;
}

QList<Goal*> Category::getGoalCollection() const {
    return goalCollection;
}

void Category::setDescription(QString d) {
    description = d;
}

void Category::setTotalTask(int n) {
    totalTask = n;
    refreshCategory();
    //notifyObservers();

}

void Category::setCompletedTask(int n) {
    completedTask = n;
    refreshCategory();
    //notifyObservers();

}


void Category::addGoal(Goal* goal) {
    goalCollection.push_back(goal);
    refreshCategory();
    //notifyObservers();
}

/* la category si aggiorna da sola ogni volta che viene aggiunto un task o ogni volta che un task viene modificato */
void Category::refreshCategory() {
    totalTask = 0;
    completedTask = 0;
    for (auto goal : goalCollection) {
        totalTask = totalTask + goal->getMax();
        completedTask = completedTask + goal->getCounter();
    }
}

void Category::attach(Observer* observer) {
    observers.push_back(observer);
}

void Category::detach(Observer* observer) {
    observers.removeAll(observer);
}

void Category::notifyObservers() {
    for (int i = 0; i < observers.size(); i++) {
        observers[i]->update();
    }
}



void Category::print() const{
    qDebug() << "Categoria: " << description << "; total Task: " << totalTask << " completed Task: " << completedTask;
    if (!goalCollection.isEmpty()) {
        for (Goal* goal : goalCollection) {
            goal->print();
        }
        qDebug() << "";
    } else {
        qDebug() << "nessun goal presente";
    }
}


void Category::printObserversList() const {
    qDebug()<<"Elenco observers del category manager: ";
    if (observers.isEmpty()) {
        qDebug()<<"lista observers vuota";
    } else {
        for (auto observer : observers) {
            qDebug()<<"one observer: ";
        }
    }
}


void Category::removeGoal(Goal* gol) {
    if (gol) {
        for (Goal* goal : goalCollection) {
            goalCollection.removeAll(gol);
            refreshCategory();
        }
    }
    notifyObservers();
}

Category::~Category() {
    observers.clear();
}
