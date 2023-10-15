#ifndef REMOVEINGREDIENT_H
#define REMOVEINGREDIENT_H

#include <QDialog>
#include "databaseheader.h"
#include "validation.h"

namespace Ui {
class RemoveIngredient;
}

class RemoveIngredient : public QDialog, public Validation
{
    Q_OBJECT

public:
    // Constructor to open ui
    explicit RemoveIngredient(QWidget *parent = nullptr);
    // check user input validity
    bool validateUserInput();
    
    void loadComboBox();
    // Destructor to delete ui pointer
    ~RemoveIngredient();

private slots:
    void on_buttonBox_accepted(); // accept to remove chosen recipe from database

    void on_btnLoad_clicked();

private:
    Ui::RemoveIngredient *ui; // pointer to ui
    QSqlDatabase database;
};

#endif // REMOVEINGREDIENT_H
