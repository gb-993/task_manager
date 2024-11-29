#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QPushButton>
#include <QProgressBar>
#include <QScrollArea>
#include "category.h"
#include "categorymanager.h"
#include "mainwindow.h"
#include "addCategoryWindow.h"



class Controller: public QObject {
Q_OBJECT
public:
    Controller();
    ~Controller();
    void addCategory(QString);
    //void removeCategory();
public  slots:
    void openDialogWindow();

private:
    QVBoxLayout *layout;
    QWidget *centralWidget;
    QPushButton *addCategoryButton;
    QPushButton *removeCategoryButton;
    QProgressBar *progressBar;
    MainWindow* mainWindow;
    CategoryManager* categoryManager;
    AddCategoryWindow* addCategoryWindow;
    QScrollArea *scrollArea;
    Category* category;

};

#endif //CONTROLLER_H
