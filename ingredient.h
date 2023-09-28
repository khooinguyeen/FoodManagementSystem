#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QDialog>
#include "databaseheader.h"
#include "addingredient.h"
#include "removeingredient.h"

namespace Ui {
class Ingredient;
}

class Ingredient : public QDialog
{
    Q_OBJECT

public:
    explicit Ingredient(QWidget *parent = nullptr);

    void loadAllIngredients();

    ~Ingredient();

private slots:
    void on_btnAdd_clicked();

    void on_btnSearch_clicked();

    void on_btnRemove_clicked();

private:
    Ui::Ingredient *ui;
    AddIngredient *ptrAddIngredient;
    RemoveIngredient *ptrRemoveIngredient;
    QSqlQueryModel *model;
};

#endif // INGREDIENT_H
