#ifndef ADDINGREDIENT_H
#define ADDINGREDIENT_H

#include <QDialog>
#include "databaseheader.h"

namespace Ui {
class AddIngredient;
}

class AddIngredient : public QDialog
{
    Q_OBJECT

public:
    explicit AddIngredient(QWidget *parent = nullptr);
    ~AddIngredient();

private slots:
    void on_btnReset_clicked();

    void on_btnSave_clicked();

private:
    Ui::AddIngredient *ui;
    QSqlDatabase database;

};

#endif // ADDINGREDIENT_H
