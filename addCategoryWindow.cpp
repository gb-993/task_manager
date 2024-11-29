/*
SISTEMATO:
1. titolo diventa uguale a ultima categoria inserita
2. aggiunta una nuova categoria tutte quelle prima assumono il suo nome
*/

#include "addCategoryWindow.h"

#include <iostream>

AddCategoryWindow::AddCategoryWindow() {
    // Impostazioni della finestra
    setWindowTitle("Aggiungi Categoria");
    setFixedSize(400, 250); // Imposta una dimensione fissa ma non troppo piccola

    // Crea i widget
    labelDescription = new QLabel("Description:");
    textEditDescription = new QTextEdit();

    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Annulla");

    // Layout principale (Verticale)
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(labelDescription);
    mainLayout->addWidget(textEditDescription);

    // Layout per i pulsanti (Orizzontale)
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch(); // Spinge i pulsanti verso destra
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);

    // Collegamenti (slot) per i pulsanti
    connect(okButton, &QPushButton::clicked, this, &AddCategoryWindow::sendDescription);
    //connect(cancelButton, &QPushButton::clicked, this, &AddCategoryWindow::reject);
}

void AddCategoryWindow::sendDescription() {
    QString descriptionText = textEditDescription->toPlainText();
    emit sendDescriptionSignal(descriptionText);
}

AddCategoryWindow::~AddCategoryWindow(){}

