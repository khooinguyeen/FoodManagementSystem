#ifndef ADDRECIPE_H
#define ADDRECIPE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AddRecipe;
}

class AddRecipe : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecipe(QWidget *parent = nullptr);
    ~AddRecipe();

private slots:
    void on_btnSave_clicked(); // button to save recipe

    void on_btnReset_clicked(); // button to reset input

private:
    Ui::AddRecipe *ui; // pointer to ui of AddRecipe feature
    QSqlDatabase database; // declare database
};

#endif // ADDRECIPE_H
