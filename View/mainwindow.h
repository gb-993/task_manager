#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QScrollArea>

#include "categoryWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QWidget *buttonContainer;
    QHBoxLayout *buttonLayout;
    QPushButton *addCategoryButton;
    QProgressBar *progressBar;
    QScrollArea *scrollArea;
    QWidget *contentWidget;
    QVBoxLayout *contentLayout;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QVBoxLayout* getLayout() const;
    void addCategory(CategoryWidget* categoryWidget);
    void removecategory(CategoryWidget* categoryWidget);
    ~MainWindow();
public slots:
    void onAddCategoryButton_clicked();
    void onDeleteCategoryButton_clicked();

    signals:
    void addCategorySignal();
    void deleteCategorySignal();

};

#endif // MAINWINDOW_H
