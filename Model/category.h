
#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>
#include <QWidget>
#include <QProgressBar>
#include <QString>
#include <QDebug>
#include "goal.h"
#include "../View/observer.h"



class Category : public QObject, public Subject
{
    Q_OBJECT
private:
    QString description;
    QList<Goal*> goalCollection;
    int totalTask;
    int completedTask;

public:
    Category(QString description = "default_category_description");
    ~Category();

    QString getDescription() const;
    int getTotalTask() const;
    int getCompletedTask() const;
    void setDescription(QString);
    void setTotalTask(int);
    void setCompletedTask(int);
    QList<Goal*> getGoalCollection() const;

    void attach(Observer *) override;
    void detach(Observer *) override;
    void notifyObservers() override;


    void print() const;
    void printObserversList() const;
    void addGoal(Goal*); // apre QDialog per creazione (secondo modo per aggiungere sensore;
    void removeGoal(Goal*); // serve al distruttore
    void refreshCategory();     // ogni volta che aggiungo un goal aggiorna la somma di task totali e completati

};

#endif // CATEGORY_H

