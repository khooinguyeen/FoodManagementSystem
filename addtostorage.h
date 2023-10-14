#ifndef ADDTOSTORAGE_H
#define ADDTOSTORAGE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AddToStorage;
}

class AddToStorage : public QDialog
{
    Q_OBJECT

public:
    // constructor to initialize ui for AddToStorage class
    explicit AddToStorage(QWidget *parent = nullptr);
    // destructor to delete ui pointer
    ~AddToStorage();

private slots:
    // declare signal function for combo box
    void on_cbxloadIngredients_activated(int index);
    // declare signal function for ok button
    void on_btnOk_clicked();
    // declare signal function for reset button
    void on_btnReset_clicked();
    // declare signal function for each item in the combo box
    void on_btnLoadIngredients_clicked();

private:
    // declare ui pointer
    Ui::AddToStorage *ui;
};

#endif // ADDTOSTORAGE_H
