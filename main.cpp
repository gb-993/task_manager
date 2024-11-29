#include "mainwindow.h"
#include "category.h"
#include "goal.h"
#include <QApplication>

#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Controller c1;

    return a.exec();
}
