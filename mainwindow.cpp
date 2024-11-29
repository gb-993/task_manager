#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QVBoxLayout *layout, QWidget *centralWidget) :
 QMainWindow(parent), layout(layout ? layout : new QVBoxLayout()), centralWidget(centralWidget ? centralWidget : new QWidget()){
    resize(800,600);
    setCentralWidget(centralWidget);              // lo aggiunge al centralwidget ufficiale
}

QVBoxLayout* MainWindow::getLayout() const {
    return layout;
}

MainWindow::~MainWindow() {}
