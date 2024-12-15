
#include "categorymanager.h"

CategoryManager::CategoryManager() {
    totalTask=0;
    completedTask=0;
}

QList<Category*> CategoryManager::getCategories() const {
    return categoryCollection;
}

int CategoryManager::getTotalTask() const {
    return totalTask;
}

int CategoryManager::getCompletedTask() const {
    return completedTask;
}

void CategoryManager::setTotalTask(int n) {
    totalTask = n;

}

void CategoryManager::setCompletedTask(int n) {
    completedTask = n;

}

void CategoryManager::print() const{
    qDebug()<<"CategoryManager: ";
    if (categoryCollection.isEmpty()){
        qDebug()<<"lista categorie vuota";
    }
    else {
        for (auto category : categoryCollection){
            qDebug()<<"category: "<<category->getDescription()<<category->getTotalTask()<<category->getCompletedTask();
            for (auto goal : category->getGoalCollection()) {
                qDebug()<< "goal: "<<goal->getDescription()<<goal->getMax()<<goal->getCounter();
            }
        }
    }
}

void CategoryManager::printObserversList() const {
    qDebug()<<"Elenco observers del category manager: ";
    if (observers.isEmpty()) {
        qDebug()<<"lista observers vuota";
    } else {
        for (auto observer : observers) {
            qDebug()<<"one observer: ";
        }
    }
}

void CategoryManager::addCategory(Category* category){
    if (category) {
        categoryCollection.push_back(category);
    }
}

void CategoryManager::removeCategory(Category* category) {
    for (Goal* goal : category->getGoalCollection()) {
        delete goal; // Elimina il goal
    }
    categoryCollection.removeOne(category);
    delete category;

}

void CategoryManager::refreshCategoryManager() {
    qDebug()<<"refresh category manager";
    qDebug()<<"totalTask before start: "<<totalTask;
    qDebug()<<"completedTask before start: "<<completedTask;
    totalTask = 0;
    completedTask = 0;
    for (auto cat : categoryCollection) {
        for (auto goal : cat->getGoalCollection()) {
            totalTask = totalTask + goal->getMax();
            completedTask = completedTask + goal->getCounter();
        }
    }
    qDebug()<<"totalTask after : "<<totalTask;
    qDebug()<<"completedTask after : "<<completedTask;
    notifyObservers();
}

void CategoryManager::attach(Observer* observer) {
    observers.push_back(observer);
}

void CategoryManager::detach(Observer* observer) {
    observers.removeAll(observer);
}

void CategoryManager::notifyObservers() {
    for (auto observer : observers) {
        observer->update();
    }
}

CategoryManager::~CategoryManager() {
    observers.clear();
}