/* Un Goal è formato da:
    descrizione
    categoria
    min (i task minimi da fare == 0) evitabile se metto tutto unsigned int
    max (i task totali da fare)
    counter (i task completati)

    categoria: immodificabile
    ogni volta che modifico il resto emette un signal
*/


#ifndef GOAL_H
#define GOAL_H

#include <QObject>
#include <QWidget>
#include <QString>


class Goal : public QObject
{
    Q_OBJECT
private:
    QString description;
    QString category;
    int max;
    int min;
    int counter;
signals:
    void updateTaskSignal();
public:
    Goal(QString d = "default_description", int ma = 4);

    void print() const;
    void addOne();
    void removeOne();

    QString getDescription() const;
    QString getCategory() const;
    int getCounter() const;
    int getMax() const;
    int getMin() const;

    void setDescription(QString description);
    void setCategory(QString category);
    void setMax(int max);

    ~Goal();
};

#endif // GOAL_H

