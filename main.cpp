#include "View/mainwindow.h"
#include "View/addCategoryDialog.h"
#include "Model/category.h"
#include <QApplication>
#include "Controller/controller.h"
#include "Model/categorymanager.h"
#include "View/addTaskDialog.h"
#include "View/taskWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CategoryManager category_manager;
    MainWindow main_window(&category_manager);
    category_manager.attach(&main_window);

    AddCategoryDialog add_category_dialog;
    AddTaskDialog add_task_dialog;

    Controller c1(&category_manager, &main_window, &add_category_dialog, &add_task_dialog, nullptr);
    main_window.show();

    return a.exec();
}
