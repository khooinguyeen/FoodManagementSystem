#ifndef ADDINGREDIENT_H
#define ADDINGREDIENT_H

#include <QDialog>
#include "databaseheader.h"
#include "validation.h"

namespace Ui {
class AddIngredient;
}

class AddIngredient : public QDialog, public Validation
{
    Q_OBJECT

public:
    // Constructor to initialize ui pointer
    explicit AddIngredient(QWidget *parent = nullptr);
    // check user input validity
    bool validateUserInput();
    // destructor to delete ui pointer
    ~AddIngredient();

private slots:
    void on_btnReset_clicked(); // Reset the inputs when the reset button is clicked

    void on_btnSave_clicked(); // Save new ingredient when the save button is clicked

private:
    Ui::AddIngredient *ui;
    QSqlDatabase database;

};

#endif // ADDINGREDIENT_H
