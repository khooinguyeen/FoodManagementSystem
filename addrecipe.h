#ifndef ADDRECIPE_H
#define ADDRECIPE_H

#include <QDialog>
#include "databaseheader.h"
#include "validation.h"

namespace Ui {
class AddRecipe;
}

class AddRecipe : public QDialog, public Validation
{
    Q_OBJECT

public:
    // Constructor to initialize ui pointer
    explicit AddRecipe(QWidget *parent = nullptr);
    // check user input validity
    bool validateUserInput();
    // Destructor to delete ui pointer
    ~AddRecipe();
    friend class TestAddRecipe;

private slots:
    void on_btnSave_clicked(); // button to save recipe

    void on_btnReset_clicked(); // button to reset input

private:
    Ui::AddRecipe *ui; // pointer to ui of AddRecipe feature
    QSqlDatabase database; // declare database
};

#endif // ADDRECIPE_H
