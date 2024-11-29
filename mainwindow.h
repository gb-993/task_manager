#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include "category.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QVBoxLayout *layout;
    QWidget *centralWidget;

public:
    explicit MainWindow(QWidget *parent = nullptr, QVBoxLayout* layout = nullptr, QWidget* centralWidget = nullptr);
    QVBoxLayout* getLayout() const;
    ~MainWindow() ;
};

#endif // MAINWINDOW_H
