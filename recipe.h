#ifndef RECIPE_H
#define RECIPE_H

#include <QDialog>
#include "removerecipe.h"
#include "addrecipe.h"

namespace Ui {
class Recipe;
}

class Recipe : public QDialog
{
    Q_OBJECT

public:
    explicit Recipe(QWidget *parent = nullptr);
    void loadAllRecipes(); // load all the recipes available in database
    ~Recipe();

private slots:
    void on_btnAdd_clicked(); // button that open the AddRecipe window

    void on_btnRemove_clicked(); // button that open the RemoveRecipe window

    void on_btnSearch_clicked(); // button to search for recipe

    void on_btnRefresh_clicked(); // button to refresh the table

private:
    Ui::Recipe *ui;
    AddRecipe *ptrAddRecipe;
    RemoveRecipe *ptrRemoveRecipe;
    QSqlQueryModel *model;
};

#endif // RECIPE_H
