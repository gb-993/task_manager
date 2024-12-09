#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent){

    // Crea il central widget e il layout principale
    centralWidget = new QWidget();
    mainLayout = new QVBoxLayout(centralWidget); // Layout principale verticale

    buttonContainer = new QWidget(); // Contenitore per i pulsanti
    buttonLayout = new QHBoxLayout(buttonContainer); // Layout orizzontale per i pulsanti
    addCategoryButton = new QPushButton("Add");
    addCategoryButton->setFixedSize(50, 30);

    buttonLayout->addWidget(addCategoryButton);
    buttonLayout->addStretch(); // Spinge i pulsanti verso sinistra
    mainLayout->addWidget(buttonContainer);

    progressBar = new QProgressBar();
    progressBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Espansione orizzontale
    mainLayout->addWidget(progressBar);

    /* scrollArea per aggiungere i catgoryWidget */
    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    contentWidget = new QWidget();
    contentLayout = new QVBoxLayout(contentWidget);
    // aggiunta categoryWidget al layout
    scrollArea->setWidget(contentWidget);
    mainLayout->addWidget(scrollArea);

    setCentralWidget(centralWidget);
    resize(600,600);


    connect(addCategoryButton, &QPushButton::clicked, this, &MainWindow::onAddCategoryButton_clicked);
}

QVBoxLayout* MainWindow::getLayout() const {
    return mainLayout;
}

void MainWindow::onAddCategoryButton_clicked() {
    emit addCategorySignal();
}
void MainWindow::onDeleteCategoryButton_clicked() {
    emit deleteCategorySignal();
}

void MainWindow::addCategory(CategoryWidget* category_widget) {
    //category_widget->show();
    contentLayout->addWidget(category_widget);
    qDebug() << "Category widget added.";
}

void MainWindow::removecategory(CategoryWidget* category_widget) {
    contentLayout->removeWidget(category_widget);
    qDebug() << "Category widget removed.";

}
MainWindow::~MainWindow() {}
