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

    void loadAllIngredients(); // Load all the ingredients in the database

    ~Ingredient();

private slots:
    void on_btnAdd_clicked(); // Button to open the AddIngredient window

    void on_btnSearch_clicked(); // Button to search for ingredient

    void on_btnRemove_clicked(); // Button to open the RemoveIngredient window

    void on_btnRefresh_clicked();

private:
    Ui::Ingredient *ui;
    AddIngredient *ptrAddIngredient;
    RemoveIngredient *ptrRemoveIngredient;
    QSqlQueryModel *model; // Query model to perform the search function
};

#endif // INGREDIENT_H
