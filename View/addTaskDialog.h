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
#include <QPushButton>


class AddTaskDialog: public QDialog{
Q_OBJECT
public:
  AddTaskDialog(QWidget *parent = 0);
  ~AddTaskDialog();
  void onOkClicked();
  void onCancelClicked();


private:
  QString taskName;
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
  void okSignal(QString, int);
};



#endif //ADDTASKDIALOG_H