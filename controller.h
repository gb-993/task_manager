#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QDebug>
#include "View/mainwindow.h"
#include "View/addCategoryDialog.h"
#include "Model/category.h"
#include "Model/categorymanager.h"
#include "View/categoryWidget.h"
#include "Model/categorymanager.h"
#include "View/categoryWidget.h"
#include "Model/goal.h"
#include "View/addTaskDialog.h"

class Controller: public QObject {
    Q_OBJECT
    public:
    Controller(CategoryManager*, MainWindow*, AddCategoryDialog*, AddTaskDialog*, QObject*);
    ~Controller();
    void onAddcategorySignal();
    void onAddTaskSignal();
    //void onOkSignal();
    void addCategoryWidget(QString, int);
    void addTaskWidget(QString, int);
    void deleteCategoryWidget(CategoryWidget*);
    void printTest();

private:
    MainWindow* mainwindow;
    AddCategoryDialog* addCategoryDialog;
    AddTaskDialog* addTaskDialog;
    CategoryManager* categoryManager;
    Category* category;
    CategoryWidget* categoryWidget;
    Goal* goal;


signals:
    void openAddCategoryDialog();
};

#endif //CONTROLLER_H
