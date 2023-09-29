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
    void loadAllRecipes();
    ~Recipe();

private slots:
    void on_btnAdd_clicked();

    void on_btnRemove_clicked();

    void on_btnSearch_clicked();

private:
    Ui::Recipe *ui;
    AddRecipe *ptrAddRecipe;
    RemoveRecipe *ptrRemoveRecipe;
    QSqlQueryModel *model;
};

#endif // RECIPE_H
