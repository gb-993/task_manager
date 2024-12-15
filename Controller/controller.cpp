
#include "controller.h"

Controller::Controller(CategoryManager* category_manager, MainWindow* mainwindow, AddCategoryDialog* add_category_dialog, AddTaskDialog* add_task_dialog,QObject *parent = nullptr) :
categoryManager(category_manager), mainwindow(mainwindow), addCategoryDialog(add_category_dialog), addTaskDialog(add_task_dialog), QObject(parent){


    connect(mainwindow, &MainWindow::addCategorySignal, this, &Controller::openAddCategoryDialog);
    connect(mainwindow, &MainWindow::deleteButtonClickedSignal, this, &Controller::onRemoveCategory);

    connect(mainwindow, &MainWindow::addTaskButtonClickedSignal, this, &Controller::openAddTaskDialog);
    connect(mainwindow, &MainWindow::deleteTaskButtonClickedSignal, this, &Controller::onRemoveTask);
    connect(mainwindow, &MainWindow::plusTaskButtonSignal, this, &Controller::addOne);
    connect(mainwindow, &MainWindow::minusTaskButtonSignal, this, &Controller::minusOne);

    connect(add_category_dialog, &AddCategoryDialog::okSignal, this, &Controller::addCategory);
    connect(add_task_dialog, &AddTaskDialog::okSignal, this, &Controller::addTask);
}

void Controller::openAddCategoryDialog() {
    addCategoryDialog->show();
}

void Controller::openAddTaskDialog(Category* cat) {
    addTaskDialog->setCategory(cat);
    addTaskDialog->show();
}

void Controller::addTask(QString taskName, int totGoal, Category* cat) {
    Goal* goal = new Goal(taskName, totGoal);
    goal->attach(mainwindow);
    goal->setCategory(cat->getDescription());
    cat->addGoal(goal);
    categoryManager->refreshCategoryManager();

}

/* crea e aggiunge la category */
void Controller::addCategory(QString categoryDescription) {
    category = new Category(categoryDescription);
    category->attach(mainwindow);
    categoryManager->addCategory(category);
    categoryManager->refreshCategoryManager();

}

void Controller::onRemoveCategory(Category* cat) {
    categoryManager->removeCategory(cat);
    categoryManager->refreshCategoryManager();
}

void Controller::onRemoveTask(Category* cat, Goal* gol) {
    cat->removeGoal(gol);
    categoryManager->refreshCategoryManager();


}

void Controller::addOne(Category* cat, Goal* gol) {
    gol->addOne();
    cat->setTotalTask(gol->getMax());
    categoryManager->refreshCategoryManager();

}

void Controller::minusOne(Category* cat, Goal* gol) {
    gol->removeOne();
    cat->setCompletedTask(gol->getCounter());
    categoryManager->refreshCategoryManager();

}

void Controller::printTest(QString categoryDescription) {
}

Controller::~Controller(){}