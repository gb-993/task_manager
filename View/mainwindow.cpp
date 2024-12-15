#include "mainwindow.h"

MainWindow::MainWindow(CategoryManager* category_manager, QWidget *parent) : categoryManager(category_manager), QMainWindow(parent){

    //centralWidget = new QWidget(this);
    totalWidget = new QWidget(this);
    //QWidget* centralWidget = new QWidget(this); // Crea un widget centrale
    mainLayout = new QVBoxLayout(totalWidget); // Layout principale verticale
    setCentralWidget(totalWidget);

    buttonContainer = new QWidget(); // Contenitore per i pulsanti
    buttonLayout = new QHBoxLayout(buttonContainer); // Layout orizzontale per i pulsanti
    addCategoryButton = new QPushButton("Add");
    printButton = new QPushButton("Print");
    addCategoryButton->setFixedSize(50, 30);

    buttonLayout->addWidget(addCategoryButton);
    buttonLayout->addWidget(printButton);
    buttonLayout->addStretch(); // Spinge i pulsanti verso sinistra
    mainLayout->addWidget(buttonContainer);

    progressBar = new QProgressBar();

    if (categoryManager->getTotalTask() == 0 && categoryManager->getCompletedTask() == 0) {
        progressBar->setEnabled(false); // Disabilita la progress bar
    } else {
        progressBar->setEnabled(true);  // Riattiva la progress bar
        progressBar->setRange(0, categoryManager->getTotalTask());
        progressBar->setValue(categoryManager->getCompletedTask());
    }

    progressBar->setFormat("%v/%m");
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

    resize(600,600);

    connect(addCategoryButton, &QPushButton::clicked, this, &MainWindow::onAddCategoryButton_clicked);
    connect(printButton, &QPushButton::clicked, this, &MainWindow::onPrintButton_clicked);

}

void MainWindow::onAddCategoryButton_clicked() {
    emit addCategorySignal();
}

void MainWindow::onPrintButton_clicked() {
    qDebug()<<"mainwindow:categorymanager total task" << categoryManager->getTotalTask();
    qDebug()<<"mainwindow:categorymanager completed task" << categoryManager->getCompletedTask();
    if (contentLayout->count() > 0) {
        for (int i = 0; i < contentLayout->count(); ++i) {
            QLayoutItem *item = contentLayout->itemAt(i);
            // Controlla se è un widget
            if (QWidget *widget = item->widget()) {
                qDebug() << "Widget trovato:" << widget->metaObject()->className() << i;
            }
        }
    }else {
        qDebug() << "No categories found";
    }
}
void MainWindow::update() {
    clearMainWindowLayout();
    for ( Category* category : categoryManager->getCategories() ) {
        categoryWidget = new CategoryWidget(category);
        /* connect per delete e add task */
        connect(categoryWidget, &CategoryWidget::deleteButtonClickedSignal, this, &MainWindow::onDeleteButtonClicked);
        connect(categoryWidget, &CategoryWidget::addTaskButtonClickedSignal, this, &MainWindow::onAddTaskButtonClicked);

        connect(categoryWidget, &CategoryWidget::deleteTaskButtonClickedSignal, this, &MainWindow::onDeleteTaskButtonClicked);
        connect(categoryWidget, &CategoryWidget::plusTaskButtonSignal, this, &MainWindow::onPlusTaskButtonClicked);
        connect(categoryWidget, &CategoryWidget::minusTaskButtonSignal, this, &MainWindow::onMinusTaskButtonClicked);

        categoryWidget->update();
        contentLayout->addWidget(categoryWidget);
    }
    progressBar->setRange(0,categoryManager->getTotalTask());
    progressBar->setValue(categoryManager->getCompletedTask());

}

void MainWindow::clearMainWindowLayout() {
    while (QLayoutItem* item = contentLayout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {

            // Se il widget è un CategoryWidget, stacca gli osservatori
            if (auto* categoryWidget = qobject_cast<CategoryWidget*>(widget)) {
                //categoryWidget->clearCatWidgetLayout();
                if (categoryWidget->getCategory()) {
                }
            }
            widget->deleteLater(); // Elimina il widget
        }

        delete item; // Elimina l'item del layout
    }


}

void MainWindow::onDeleteButtonClicked(Category* cat) {
    emit deleteButtonClickedSignal(cat);
}

void MainWindow::onAddTaskButtonClicked(Category* cat) {
    emit addTaskButtonClickedSignal(cat);
}

void MainWindow::onDeleteTaskButtonClicked(Category* cat, Goal* gol) {
    emit deleteTaskButtonClickedSignal(cat, gol);
}

void MainWindow::onPlusTaskButtonClicked(Category* cat, Goal* gol) {
    emit plusTaskButtonSignal(cat, gol);
}

void MainWindow::onMinusTaskButtonClicked(Category* cat, Goal* gol) {
    emit minusTaskButtonSignal(cat, gol);
}

void MainWindow::addCategory(CategoryWidget* category_widget) {
    contentLayout->addWidget(category_widget);
}



MainWindow::~MainWindow() {}
