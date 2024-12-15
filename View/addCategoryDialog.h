#ifndef ADDCATEGORYDIALOG_H
#define ADDCATEGORYDIALOG_H
#include <QInputDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpinBox>


class AddCategoryDialog: public QDialog{
Q_OBJECT
    public:
    AddCategoryDialog(QDialog *parent = nullptr);
    ~AddCategoryDialog();

public slots:
    void onOkClicked();
    void onCancelClicked();

    private:
    QVBoxLayout *mainLayout;
    QLabel *descriptionLabel;
    QLineEdit *descriptionCategoryLineEdit;
    QHBoxLayout *descriptionLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QHBoxLayout *buttonLayout;

    signals:
    void okSignal(QString);

};



#endif //ADDCATEGORYDIALOG_H
