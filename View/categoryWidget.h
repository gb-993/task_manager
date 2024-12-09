//
// Created by gb on 09/12/24.
//

#ifndef CATEGORYWIDGET_H
#define CATEGORYWIDGET_H
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QScrollArea>
#include "../Model/category.h"


class CategoryWidget: public QWidget {
Q_OBJECT
    public:
    explicit CategoryWidget(QWidget *parent = nullptr, Category *category = nullptr);
    ~CategoryWidget();
    void onDeleteButtonClicked();
    void onAddTaskButtonClicked();
    void deleteSelf();
    Category* getCategory();
    void printTest();


private:
    Category *category;
    QLabel *title;
    QPushButton *deleteButton;
    QHBoxLayout *titleAndDeleteLayout;
    QVBoxLayout *mainLayout;
    QHBoxLayout *progressAndButtonLayout;
    QProgressBar *progressBar;
    QPushButton *addTaskButton;
    QHBoxLayout *counterLayout;
    QLabel *totalTaskLabel;
    QLabel *completedTaskLabel;
    QScrollArea *scrollArea;
    QWidget *contentWidget;
    QVBoxLayout *contentLayout;

    signals:
    void deleteButtonClickedSignal(CategoryWidget*);
    void addTaskButtonClickedSignal();

};



#endif //CATEGORYWIDGET_H
