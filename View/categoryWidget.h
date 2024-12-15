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
#include "observer.h"
#include "taskWidget.h"
#include "../Model/category.h"      /* la osserva per le modifiche alla progress bar e counter */

class CategoryWidget: public QWidget, public Observer{
Q_OBJECT
    public:
    explicit CategoryWidget(Category*, QWidget *parent = nullptr);
    ~CategoryWidget();

    Category* getCategory() const;
    void update() override;


    void onDeleteButtonClicked();
    void onAddTaskButtonClicked();
    void onDeleteTaskButtonClicked(Goal*);
    void onPlusTaskButtonClicked(Goal*);
    void onMinusTaskButtonClicked(Goal*);

    void addTask(TaskWidget*);
    void clearCatWidgetLayout();
    void deleteSelf();
    void printTest();

    QList<TaskWidget*> getTaskWidgets() const ;
    void addTaskWidget(TaskWidget* taskWidget) ;



private:
    Category* category;
    TaskWidget* taskWidget;
    QLabel *title;
    QPushButton *deleteButton;
    QPushButton *printButton;
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
    void deleteButtonClickedSignal(Category*);
    void addTaskButtonClickedSignal(Category*);
    void deleteTaskButtonClickedSignal(Category*, Goal*);
    void plusTaskButtonSignal(Category*, Goal*);
    void minusTaskButtonSignal(Category*, Goal*);

};



#endif //CATEGORYWIDGET_H
