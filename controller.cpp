//
// Created by gb on 08/12/24.
//

#include "controller.h"




Controller::Controller(CategoryManager* category_manager, MainWindow* mainwindow, AddCategoryDialog* add_category_dialog, AddTaskDialog* add_task_dialog,QObject *parent = nullptr) :
categoryManager(category_manager), mainwindow(mainwindow), addCategoryDialog(add_category_dialog),addTaskDialog(add_task_dialog), QObject(parent){

    connect(mainwindow, &MainWindow::addCategorySignal, this, &Controller::onAddcategorySignal);            //  quando faccio add new category dalla main view
    connect(add_category_dialog, &AddCategoryDialog::okSignal, this, &Controller::addCategoryWidget);       // quando premo ok dalla new category dialog
    connect(add_task_dialog, &AddTaskDialog::okSignal, this, &Controller::addTaskWidget);       // quando premo ok dalla new task dialog


}

void Controller::onAddcategorySignal() {
    addCategoryDialog->show();
}
void Controller::onAddTaskSignal() {
    addTaskDialog->show();
}
// crea un widget categoria da passare alla mainWindow
void Controller::addCategoryWidget(QString description, int totTask){
    category = new Category(description, totTask);
    categoryManager->addCategory(category);
    categoryWidget = new CategoryWidget(nullptr, category);
    mainwindow->addCategory(categoryWidget);
    connect(categoryWidget, &CategoryWidget::deleteButtonClickedSignal, this, &Controller::deleteCategoryWidget);  // quando chiamo delete dalla categoriaWidget
    connect(categoryWidget, &CategoryWidget::addTaskButtonClickedSignal, this, &Controller::onAddTaskSignal);
}

void Controller::addTaskWidget(QString description, int totTask) {
    goal = new Goal(description, totTask);
}


void Controller::deleteCategoryWidget(CategoryWidget* category_widget) {
    categoryManager->removeCategory(category_widget->getCategory());
    mainwindow->removecategory(category_widget);
    category_widget->deleteSelf();
}


void Controller::printTest() {
    qDebug()<<"printTest";
}

Controller::~Controller(){}