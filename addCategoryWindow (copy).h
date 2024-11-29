#ifndef ADDCATEGORYWINDOW_H
#define ADDCATEGORYWINDOW_H


#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

class AddCategoryWindow: public QDialog {
    Q_OBJECT
public:
    AddCategoryWindow();
    ~AddCategoryWindow();
    void sendDescription();
private:
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *labelDescription;
    QTextEdit *textEditDescription; // Aggiunto QTextEdit per la descrizione

    signals:
    void sendDescriptionSignal(QString);

};



#endif //ADDCATEGORYWINDOW_H
