//
// Created by gb on 09/12/24.
//

#include "categoryWidget.h"

CategoryWidget::CategoryWidget(QWidget* parent, Category* category): QWidget(parent), category(category) {
    mainLayout = new QVBoxLayout(); // Layout principale verticale

    /* creazione e aggiunta titolo e delete button */
    title = new QLabel();
    title->setText(category->getDescription());
    deleteButton = new QPushButton();
    deleteButton->setText("delete");
    deleteButton->setFixedSize(50,30);
    titleAndDeleteLayout = new QHBoxLayout();
    titleAndDeleteLayout->addWidget(title);
    titleAndDeleteLayout->addWidget(deleteButton);
    titleAndDeleteLayout->addStretch();
    mainLayout->addLayout(titleAndDeleteLayout);

    /* creazione e aggiunta progress bar e button addTask */
    progressAndButtonLayout = new QHBoxLayout();
    progressBar = new QProgressBar();
    addTaskButton = new QPushButton();
    addTaskButton->setText("Add Task");
    progressAndButtonLayout->addWidget(progressBar);
    progressAndButtonLayout->addWidget(addTaskButton);
    mainLayout->addLayout(progressAndButtonLayout);

    /* creazione e aggiunta label totali e completati */
    counterLayout = new QHBoxLayout();
    totalTaskLabel = new QLabel();
    totalTaskLabel->setText(QString::number(category->getTotalTask()));
    completedTaskLabel = new QLabel();
    completedTaskLabel->setText(QString::number(category->getCompletedTask()));
    counterLayout->addWidget(totalTaskLabel);
    counterLayout->addWidget(completedTaskLabel);
    mainLayout->addLayout(counterLayout);

    /* scrollArea per aggiungere i Tasks */
    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    contentWidget = new QWidget();
    contentLayout = new QVBoxLayout(contentWidget);
    // aggiunta tasks al layout
    scrollArea->setWidget(contentWidget);
    mainLayout->addWidget(scrollArea);

    /* step finale */
    setLayout(mainLayout);

    /* connect */
    connect(deleteButton, &QPushButton::clicked, this, &CategoryWidget::onDeleteButtonClicked);
    connect(addTaskButton, &QPushButton::clicked, this, &CategoryWidget::onAddTaskButtonClicked);
}

Category* CategoryWidget::getCategory() {
    return category;
}

void CategoryWidget::onDeleteButtonClicked() {
    emit deleteButtonClickedSignal(this);
}

// deve inviare anche la categoria
void CategoryWidget::onAddTaskButtonClicked() {
    emit addTaskButtonClickedSignal();
}
void CategoryWidget::deleteSelf() {
    delete this;
}

void CategoryWidget::printTest() {
    category->print();
}

CategoryWidget::~CategoryWidget() {}