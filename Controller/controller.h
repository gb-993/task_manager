#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QDebug>
#include "../View/mainwindow.h"
#include "../View/addCategoryDialog.h"
#include "../Model/category.h"
#include "../Model/categorymanager.h"
#include "../View/categoryWidget.h"
#include "../Model/categorymanager.h"
#include "../View/categoryWidget.h"
#include "../Model/goal.h"
#include "../View/addTaskDialog.h"

class Controller: public QObject {
    Q_OBJECT
    public:
    Controller(CategoryManager*, MainWindow*, AddCategoryDialog*, AddTaskDialog*, QObject*);
    ~Controller();

    void openAddCategoryDialog();
    void openAddTaskDialog(Category*);
    void addCategory(QString);
    void addTask(QString, int, Category*);
    void onRemoveCategory(Category*);
    void onRemoveTask(Category*, Goal*);
    void addOne(Category*, Goal*);
    void minusOne(Category*, Goal*);
    void printTest(QString);

private:
    MainWindow* mainwindow;
    AddCategoryDialog* addCategoryDialog;
    AddTaskDialog* addTaskDialog;
    CategoryManager* categoryManager;
    Category* category;
    CategoryWidget* categoryWidget;
    Goal* goal;


};

#endif //CONTROLLER_H
