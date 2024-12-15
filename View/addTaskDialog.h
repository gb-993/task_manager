//
// Created by gb on 09/12/24.
//

#ifndef ADDTASKDIALOG_H
#define ADDTASKDIALOG_H
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include "../Model/category.h"
#include <QPushButton>


class AddTaskDialog: public QDialog{
Q_OBJECT
public:
  AddTaskDialog( QWidget *parent = 0);
  ~AddTaskDialog();
  void onOkClicked();
  void onCancelClicked();
  void setCategory(Category* category);
  Category* getCategory() const;


private:
  QString taskName;
  Category* category;

  QVBoxLayout *mainLayout;
  QLabel *descriptionLabel;
  QLineEdit *descriptionTaskLineEdit;
  QHBoxLayout *descriptionLayout;

  QLabel *totalTaskLabel;
  QSpinBox *totalTaskSelector;
  QHBoxLayout *counterLayout;

  QPushButton *okButton;
  QPushButton *cancelButton;
  QHBoxLayout *buttonLayout;

  signals:
  void okSignal(QString, int, Category*);
};



#endif //ADDTASKDIALOG_H
