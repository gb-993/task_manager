//
// Created by gb on 09/12/24.
//

#include "categoryWidget.h"

CategoryWidget::CategoryWidget(Category* cat,QWidget* parent): category(cat), QWidget(parent) {
    mainLayout = new QVBoxLayout(); // Layout principale verticale

    /* creazione e aggiunta titolo e delete button */
    title = new QLabel();
    title->setAlignment(Qt::AlignCenter);
    title->setText(category->getDescription());
    deleteButton = new QPushButton();
    deleteButton->setText("delete");
    deleteButton->setFixedSize(50,30);

    printButton = new QPushButton();
    printButton->setText("print");
    printButton->setFixedSize(50,30);

    titleAndDeleteLayout = new QHBoxLayout();
    titleAndDeleteLayout->addWidget(title);
    titleAndDeleteLayout->addWidget(deleteButton);
    titleAndDeleteLayout->addWidget(printButton);
    titleAndDeleteLayout->addStretch();
    mainLayout->addLayout(titleAndDeleteLayout);

    /* creazione e aggiunta progress bar e button addTask */
    progressAndButtonLayout = new QHBoxLayout();
    progressBar = new QProgressBar();
    progressBar->setRange(0,category->getTotalTask());
    progressBar->setValue(category->getCompletedTask());
    progressBar->setFormat("%v/%m");
    addTaskButton = new QPushButton();
    addTaskButton->setText("Add Task");
    progressAndButtonLayout->addWidget(progressBar);
    progressAndButtonLayout->addWidget(addTaskButton);
    mainLayout->addLayout(progressAndButtonLayout);

    /* creazione e aggiunta label totali e completati */
    counterLayout = new QHBoxLayout();
    totalTaskLabel = new QLabel();
    completedTaskLabel = new QLabel();
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
    connect(printButton, &QPushButton::clicked, this, &CategoryWidget::printTest);
    connect(addTaskButton, &QPushButton::clicked, this, &CategoryWidget::onAddTaskButtonClicked);

}

Category* CategoryWidget::getCategory() const {
    return category;
}

/* quello che cancella la categoria intera */
void CategoryWidget::onDeleteButtonClicked() {
    emit deleteButtonClickedSignal(category);
}


void CategoryWidget::onAddTaskButtonClicked() {
    emit addTaskButtonClickedSignal(category);
}

void CategoryWidget::deleteSelf() {
    delete this;
}


/* deve ricevere tutta la category */
void CategoryWidget::update() {
    clearCatWidgetLayout();
    for (Goal* goal : category->getGoalCollection()) {
        taskWidget = new TaskWidget(goal);

        connect(taskWidget, &TaskWidget::deleteTaskButtonClickedSignal, this, &CategoryWidget::onDeleteTaskButtonClicked);
        connect(taskWidget, &TaskWidget::plusButtonSignal, this, &CategoryWidget::onPlusTaskButtonClicked);
        connect(taskWidget, &TaskWidget::minusButtonSignal, this, &CategoryWidget::onMinusTaskButtonClicked);

        contentLayout->addWidget(taskWidget);
    }


}

void CategoryWidget::clearCatWidgetLayout() {
    while (QLayoutItem* item = contentLayout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            if (auto* taskWidget = qobject_cast<TaskWidget*>(widget)) {
                if (taskWidget->getGoal()) {
                }
            }
            widget->deleteLater();
        }
        delete item;
    }

}

void CategoryWidget::addTask(TaskWidget* task_widget) {
    contentLayout->addWidget(task_widget);
}

QList<TaskWidget*> CategoryWidget::getTaskWidgets() const {
    QList<TaskWidget*> taskWidgets;
    for (int i = 0; i < layout()->count(); ++i) {
        if (auto* taskWidget = qobject_cast<TaskWidget*>(layout()->itemAt(i)->widget())) {
            taskWidgets.append(taskWidget);
        }
    }
    return taskWidgets;
}

void CategoryWidget::onDeleteTaskButtonClicked(Goal* gol) {
    emit deleteTaskButtonClickedSignal(category, gol);
}

void CategoryWidget::onPlusTaskButtonClicked(Goal* gol) {
    emit plusTaskButtonSignal(category, gol);
}

void CategoryWidget::onMinusTaskButtonClicked(Goal* gol) {
    emit minusTaskButtonSignal(category, gol);
}

void CategoryWidget::addTaskWidget(TaskWidget* taskWidget) {
    layout()->addWidget(taskWidget); // Aggiunge il TaskWidget al layout
}


void CategoryWidget::printTest() {
    category->print();
}

CategoryWidget::~CategoryWidget() {

}