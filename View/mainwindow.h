#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QScrollArea>
#include <QWidget>
#include "observer.h"
#include "categoryWidget.h"
#include "../Model/categorymanager.h"       /* lo osserva per sapere quando vengono aggiunte/rimosse categorie */


class MainWindow : public QMainWindow, public Observer{
    Q_OBJECT

private:
    QWidget* totalWidget;
    CategoryManager* categoryManager;
    CategoryWidget *categoryWidget;
    QVBoxLayout *mainLayout;
    QWidget *buttonContainer;
    QHBoxLayout *buttonLayout;
    QPushButton *addCategoryButton;
    QPushButton *printButton;
    QProgressBar *progressBar;
    QScrollArea *scrollArea;
    QWidget *contentWidget;
    QVBoxLayout *contentLayout;

public:
    explicit MainWindow(CategoryManager* ,QWidget *parent = nullptr);
    ~MainWindow();

    void update() override;
    void addCategory(CategoryWidget*);
    void clearMainWindowLayout();

public slots:
    void onAddCategoryButton_clicked();
    void onPrintButton_clicked();
    void onDeleteButtonClicked(Category*);
    void onAddTaskButtonClicked(Category*);
    void onDeleteTaskButtonClicked(Category*, Goal*);
    void onPlusTaskButtonClicked(Category*, Goal*);
    void onMinusTaskButtonClicked(Category*, Goal*);


signals:
    void addCategorySignal();
    void deleteButtonClickedSignal(Category*);
    void addTaskButtonClickedSignal(Category*);
    void deleteTaskButtonClickedSignal(Category*, Goal*);
    void plusTaskButtonSignal(Category*, Goal*);
    void minusTaskButtonSignal(Category*, Goal*);
};

#endif // MAINWINDOW_H
