#ifndef TASKWIDGET_H
#define TASKWIDGET_H

#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "observer.h"
#include "../Model/category.h"
#include "../Model/goal.h"      /* lo osserva per aumentare progressbar e counter*/


class TaskWidget:public QWidget, public Observer {
Q_OBJECT
public:
    explicit TaskWidget(Goal*,QWidget *parent = nullptr);
    ~TaskWidget();

    Goal* getGoal() const;
    void update() override;

    void onDeleteTaskButtonClicked();
    void onPlusButtonClicked();
    void onMinusButtonClicked();
    QString print() const;

private:
    QProgressBar *progressBar;
    QPushButton *addOneButton;
    QPushButton *minusOneButton;
    QPushButton *deleteButton;
    QLabel *descriptionLabel;
    QVBoxLayout *mainLayout;
    QHBoxLayout *descriptionAndDeleteLayout;
    QHBoxLayout *barAndButtonsLayout;
    Goal *goal;
    QString description;
    int totalTask;
    int completedTask;
signals:
    void deleteTaskButtonClickedSignal(Goal*);
    void plusButtonSignal(Goal*);
    void minusButtonSignal(Goal*);
};



#endif //TASKWIDGET_H
