//
// Created by gb on 08/12/24.
//

#include "addCategoryDialog.h"

AddCategoryDialog::AddCategoryDialog(QDialog* parent): QDialog(parent) {

    mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(6);
    mainLayout->setContentsMargins(11, 11, 11, 11);

    /* selettore nome */

    descriptionLabel = new QLabel(this);
    descriptionLabel->setText("Category: ");
    descriptionCategoryLineEdit = new QLineEdit(this);
    descriptionCategoryLineEdit->setText("set category...");
    descriptionLayout = new QHBoxLayout();
    descriptionLayout->addWidget(descriptionLabel);
    descriptionLayout->addWidget(descriptionCategoryLineEdit);
    mainLayout->addLayout(descriptionLayout);


    okButton = new QPushButton(this);
    okButton->setText("ok");
    cancelButton = new QPushButton(this);
    cancelButton->setText("cancel");
    buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(6);
    buttonLayout->setContentsMargins(11, 11, 11, 11);
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    mainLayout->addLayout(buttonLayout);

    connect(okButton, &QPushButton::clicked, this, &AddCategoryDialog::onOkClicked);
    connect(cancelButton, &QPushButton::clicked, this, &AddCategoryDialog::onCancelClicked);


}

/* manda al controller le info col nome della categoria */
void AddCategoryDialog::onOkClicked() {
    QString categoryName = descriptionCategoryLineEdit->text();
    emit okSignal(categoryName);
    this->close();
}

void AddCategoryDialog::onCancelClicked() {
    this->close();
}

AddCategoryDialog::~AddCategoryDialog(){}