//
// Created by gb on 09/12/24.
//

#include "addTaskDialog.h"

AddTaskDialog::AddTaskDialog(QWidget *parent): QDialog(parent){
    mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(6);
    mainLayout->setContentsMargins(11, 11, 11, 11);

    /* selettore nome */

    descriptionLabel = new QLabel(this);
    descriptionLabel->setText("Task name: ");
    descriptionTaskLineEdit = new QLineEdit(this);
    descriptionTaskLineEdit->setText("task name...");
    descriptionLayout = new QHBoxLayout();
    descriptionLayout->addWidget(descriptionLabel);
    descriptionLayout->addWidget(descriptionTaskLineEdit);
    mainLayout->addLayout(descriptionLayout);

    /* selettore numero task */
    totalTaskLabel = new QLabel(this);
    totalTaskLabel->setText("Total goal: ");
    totalTaskSelector = new QSpinBox(this);
    totalTaskSelector->setMinimum(1);
    totalTaskSelector->setMaximum(100);
    totalTaskSelector->setValue(0);
    counterLayout = new QHBoxLayout();
    counterLayout->addWidget(totalTaskLabel);
    counterLayout->addWidget(totalTaskSelector);
    mainLayout->addLayout(counterLayout);


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

    connect(okButton, &QPushButton::clicked, this, &AddTaskDialog::onOkClicked);
    connect(cancelButton, &QPushButton::clicked, this, &AddTaskDialog::onCancelClicked);
}

void AddTaskDialog::onOkClicked() {
    QString goalName = descriptionTaskLineEdit->text();
    int totGoal = totalTaskSelector->value();
    emit okSignal(goalName, totGoal, category);
    this->close();
}

void AddTaskDialog::setCategory(Category* cat) {
    category = cat;
}
Category* AddTaskDialog::getCategory() const {
    return category;
}
void AddTaskDialog::onCancelClicked() {
    this->close();
}

AddTaskDialog::~AddTaskDialog(){}