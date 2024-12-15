#include "taskWidget.h"

TaskWidget::TaskWidget(Goal* g, QWidget* parent) :
    goal(g),description(g->getDescription()), totalTask(g->getMax()), completedTask(g->getCounter()), QWidget(parent) {
    mainLayout = new QVBoxLayout(this);

    // Description label and delete button
    descriptionLabel = new QLabel(this);
    descriptionLabel->setAlignment(Qt::AlignLeft);
    descriptionLabel->setText(description);

    deleteButton = new QPushButton(this);
    deleteButton->setText("Delete");

    // Layout for description and delete button
    descriptionAndDeleteLayout = new QHBoxLayout();
    descriptionAndDeleteLayout->addWidget(descriptionLabel);
    descriptionAndDeleteLayout->addWidget(deleteButton);

    // Progress bar and +- buttons
    progressBar = new QProgressBar(this);
    progressBar->setRange(0,totalTask);
    progressBar->setValue(completedTask);
    progressBar->setFormat("%v/%m");
    progressBar->setAlignment(Qt::AlignCenter);

    int barHeight = progressBar->height();
    addOneButton = new QPushButton(this);
    addOneButton->setText("+");
    addOneButton->setFixedSize(barHeight,barHeight);

    minusOneButton = new QPushButton(this);
    minusOneButton->setText("-");
    minusOneButton->setFixedSize(barHeight,barHeight);

    // Layout for progress bar and +-buttons
    barAndButtonsLayout = new QHBoxLayout();
    barAndButtonsLayout->addWidget(progressBar);
    barAndButtonsLayout->addWidget(addOneButton);
    barAndButtonsLayout->addWidget(minusOneButton);

    // Add the layouts to the main layout
    mainLayout->addLayout(descriptionAndDeleteLayout);
    mainLayout->addLayout(barAndButtonsLayout);

    connect(deleteButton, &QPushButton::clicked, this, &TaskWidget::onDeleteTaskButtonClicked);
    connect(addOneButton, &QPushButton::clicked, this, &TaskWidget::onPlusButtonClicked);
    connect(minusOneButton, &QPushButton::clicked, this, &TaskWidget::onMinusButtonClicked);

}

void TaskWidget::onDeleteTaskButtonClicked() {
    emit deleteTaskButtonClickedSignal(goal);
}

void TaskWidget::onPlusButtonClicked() {
    emit plusButtonSignal(goal);
}

void TaskWidget::onMinusButtonClicked() {
    emit minusButtonSignal(goal);
}

Goal* TaskWidget::getGoal() const {
    return goal;
}

QString TaskWidget::print() const {
    return description;
}
void TaskWidget::update() {

}


TaskWidget::~TaskWidget() {

}