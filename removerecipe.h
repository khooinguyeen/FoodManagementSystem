#ifndef REMOVERECIPE_H
#define REMOVERECIPE_H

#include <QDialog>
#include "databaseheader.h"
#include "validation.h"

namespace Ui {
class RemoveRecipe;
}

class RemoveRecipe : public QDialog, public Validation
{
    Q_OBJECT

public:
    // Constructor to open ui
    explicit RemoveRecipe(QWidget *parent = nullptr);
    // check user input validity
    bool validateUserInput();
    void loadComboBox();
    // Destructor to delete ui pointer
    ~RemoveRecipe();
    friend class TestRemoveRecipe;

private slots:
    void on_buttonBox_accepted(); // accept to remove chosen recipe from database

    void on_btnLoad_clicked();

private:
    Ui::RemoveRecipe *ui; // pointer to ui of RemoveRecipe
    QSqlDatabase database; // declare database
};

#endif // REMOVERECIPE_H
