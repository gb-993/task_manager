#ifndef CATEGORYMANAGER_H
#define CATEGORYMANAGER_H

#include "../View/observer.h"
#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QList>
#include "category.h"
#include "goal.h"

class CategoryManager: public QObject, public Subject
{
    Q_OBJECT
private:
    QList<Category*> categoryCollection;
    int totalTask;
    int completedTask;
public:
    CategoryManager();
    ~CategoryManager();

    QList<Category*> getCategories() const;
    void attach(Observer *) override;
    void detach(Observer *) override;
    void notifyObservers() override;

    int getTotalTask() const;
    int getCompletedTask() const;
    void setTotalTask(int);
    void setCompletedTask(int);

    void refreshCategoryManager();
    void print() const;
    void printObserversList() const;
    void addCategory(Category*);
    void removeCategory(Category*);
};

#endif // CATEGORYMANAGER_H
