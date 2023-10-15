#ifndef REMOVERECIPE_H
#define REMOVERECIPE_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class RemoveRecipe;
}

class RemoveRecipe : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveRecipe(QWidget *parent = nullptr);
    ~RemoveRecipe();

private slots:
    void on_buttonBox_accepted(); // accept to remove chosen recipe from database

private:
    Ui::RemoveRecipe *ui; // pointer to ui of RemoveRecipe
    QSqlDatabase database; // declare database
};

#endif // REMOVERECIPE_H
