#include "controller.h"

#include <iostream>

Controller::Controller() {
    // Crea il central widget e il layout principale
    centralWidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget); // Layout principale verticale

    QWidget *buttonContainer = new QWidget(); // Contenitore per i pulsanti
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonContainer); // Layout orizzontale per i pulsanti
    buttonLayout->setContentsMargins(0, 10, 0, 0); // Margini personalizzati
    buttonLayout->setSpacing(5); // Spaziatura tra i pulsanti
    addCategoryButton = new QPushButton("Add");
    removeCategoryButton = new QPushButton("Del");
    addCategoryButton->setFixedSize(50, 30);
    removeCategoryButton->setFixedSize(50, 30);

    buttonLayout->addWidget(addCategoryButton);
    buttonLayout->addWidget(removeCategoryButton);
    buttonLayout->addStretch(); // Spinge i pulsanti verso sinistra
    mainLayout->addWidget(buttonContainer);

    progressBar = new QProgressBar();
    progressBar->setFixedHeight(20); // Altezza fissa
    progressBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Espansione orizzontale
    mainLayout->addWidget(progressBar);

    // Ridurre la spaziatura tra la progress bar e la scroll area
    mainLayout->setSpacing(5);  // Spaziatura generale nel layout
    mainLayout->setContentsMargins(0, 10, 0, 0); // Impostare i margini del layout
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);  // La QScrollArea si ridimensionerà automaticamente
    QWidget *scrollContent = new QWidget();
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);

    /* AGGIUNGERE QUA LE CATEGORIE CREATE
    scrollLayout->addWidget(testwidget);
    scrollArea->setWidget(scrollContent);
    */
    // Aggiungiamo la QScrollArea al layout principale
    mainLayout->addWidget(scrollArea);

    // Crea la finestra principale
    mainWindow = new MainWindow(nullptr, mainLayout, centralWidget);
    mainWindow->show();

    // Crea tutte le finestre necessarie

    // Crea il gestore delle categorie
    categoryManager = new CategoryManager();

    // connect
    connect(addCategoryButton, &QPushButton::clicked, this, &Controller::openDialogWindow);
}

void Controller::openDialogWindow() {
    // differenza con Category category1(description);
    addCategoryWindow = new AddCategoryWindow();
    connect(addCategoryWindow, &AddCategoryWindow::sendDescriptionSignal, this, &Controller::addCategory);
    addCategoryWindow->exec();
}

void Controller::addCategory(QString description) {
    category = new Category(description);
    categoryManager->addCategory(category);
    categoryManager->print();
    // serve??
    delete addCategoryWindow;
    addCategoryWindow = nullptr;
}

Controller::~Controller() {}
