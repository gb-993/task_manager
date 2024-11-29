#include "category.h"


Category::Category(QString d) : description(d) {
    totalTask = 0;
    completedTask = 0;

}

void Category::print() const{
    qDebug() << "Categoria " << description << "; total Task: " << totalTask << " completed Task: " << completedTask;
    if (!goalCollection.isEmpty()) {
        for (Goal* goal : goalCollection) {
            goal->print();
        }
        qDebug() << "";
    } else {
        qDebug() << "nessun goal presente";
    }
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

void Category::addGoal(Goal* goal) {
    goalCollection.push_back(goal);
    connect(goal, &Goal::updateTaskSignal, this, &Category::refreshTask);
}

void Category::removeGoal(Goal* goal) {
    goalCollection.removeOne(goal);
    refreshTask();
    if (goal) delete goal;
}

void Category::refreshTask() {
    totalTask = 0;
    completedTask = 0;
    for (auto goal : goalCollection) {
        totalTask = totalTask + goal->getMax();
        completedTask = completedTask + goal->getCounter();
    }
}

/* da rivedere
void Category::modifyGoal(Goal* goal, int max, int count) {
    if (max != goal->getMax()) {
        goal->setMax(max);
    }
    if (count != goal->getCounter()) {
        goal->setCounter(count);
    }
}
*/

Category::~Category() {
    if (!goalCollection.isEmpty()){
        for (Goal* goal : goalCollection){
            removeGoal(goal);
        }
    }
}
