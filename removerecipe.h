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
    void on_buttonBox_accepted();

private:
    Ui::RemoveRecipe *ui;
    QSqlDatabase database;
};

#endif // REMOVERECIPE_H
