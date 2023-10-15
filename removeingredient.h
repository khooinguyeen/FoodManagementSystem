#ifndef REMOVEINGREDIENT_H
#define REMOVEINGREDIENT_H

#include <QDialog>
#include "databaseheader.h"
#include "validation.h"

namespace Ui {
class RemoveIngredient;
}

class RemoveIngredient : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveIngredient(QWidget *parent = nullptr);
    ~RemoveIngredient();

private slots:
    void on_buttonBox_accepted(); // accept to remove chosen recipe from database

private:
    Ui::RemoveIngredient *ui; // pointer to ui
    QSqlDatabase database;
};

#endif // REMOVEINGREDIENT_H
