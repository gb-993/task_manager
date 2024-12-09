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
    void onOkClicked();
    void onCancelClicked();

    private:
    QString categoryName;
    QVBoxLayout *mainLayout;
    QLabel *descriptionLabel;
    QLineEdit *descriptionCategoryLineEdit;
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



#endif //ADDCATEGORYDIALOG_H
