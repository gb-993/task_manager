#ifndef GOAL_H
#define GOAL_H

#include <QList>
#include <QWidget>
#include <QString>

#include "subject.h"
#include "../View/observer.h"

class Goal : public QObject, public Subject {
    Q_OBJECT
private:
    QString description;
    QString category;
    int max;
    int min;
    int counter;
public:
    Goal(QString d = "default_description", int ma = 4);
    ~Goal();

    /* metodi get */
    QString getDescription() const;
    QString getCategory() const;
    int getCounter() const;
    int getMax() const;
    int getMin() const;

    /* metodi set */
    void setDescription(QString description);
    void setCategory(QString category);
    void setMax(int max);

    /* implementazione classi subject */
    void attach(Observer *) override;
    void detach(Observer *) override;
    void notifyObservers() override;

    /* metodi propri */
    void print() const;
    void addOne();
    void removeOne();

};

#endif // GOAL_H

