#ifndef REMOVEINGREDIENT_H
#define REMOVEINGREDIENT_H

#include <QDialog>
#include "databaseheader.h"

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
    void on_buttonBox_accepted();

private:
    Ui::RemoveIngredient *ui;
    QSqlDatabase database;
};

#endif // REMOVEINGREDIENT_H
