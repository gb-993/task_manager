/* Una categoria possiede:
    descrizione
    lista di goal
    un totale di task (somma di tutti i goal)
    un totale di task completati (somma di tutti i goal)

Una categoria può:
    aggiungere goal
    rimuovere goal
    modificare goal (forse no)
    */


#ifndef CATEGORY_H
#define CATEGORY_H

#include <QObject>
#include <QWidget>
#include <QProgressBar>
#include <QString>
#include <QDebug>
#include "goal.h"


class Category : public QObject
{
    Q_OBJECT
private:
    QString description;
    QList<Goal*> goalCollection;
    int totalTask;
    int completedTask;

public:
    Category(QString description = "default_category_description");
    void print() const;
    QString getDescription() const;
    int getTotalTask() const;
    int getCompletedTask() const;
    ~Category();

public slots:
    void addGoal(Goal*); // apre QDialog per creazione (secondo modo per aggiungere sensore;
    void removeGoal(Goal*); // effetto su quello selezionato
    void refreshTask();     // ogni volta che aggiungo un goal aggiorna la somma di task totali e completati
    // void modifyGoal(Goal*, int, int); // apre una QDialog per modificare dati ( visitor per modificarla a seconda del sensore)

};

#endif // CATEGORY_H

