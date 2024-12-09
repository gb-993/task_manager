#include "View/mainwindow.h"
#include "View/addCategoryDialog.h"
#include "Model/category.h"
#include <QApplication>
#include "controller.h"
#include "Model/categorymanager.h"
#include "View/addTaskDialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CategoryManager categoryManager;
    MainWindow w;
    AddCategoryDialog add_category_dialog;
    AddTaskDialog add_task_dialog;
    Controller c1(&categoryManager, &w, &add_category_dialog, &add_task_dialog, nullptr);
    w.show();

    return a.exec();
}
