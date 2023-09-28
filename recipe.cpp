#include "recipe.h"
#include "ui_recipe.h"

Recipe::Recipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recipe)
{
    ui->setupUi(this);
    ptrAddRecipe = new AddRecipe();
    ptrRemoveRecipe = new RemoveRecipe();
}

Recipe::~Recipe()
{
    delete ui;
    delete ptrAddRecipe;
    delete ptrRemoveRecipe;
}

void Recipe::on_btnAdd_clicked()
{
    ptrAddRecipe->show();
}


void Recipe::on_btnRemove_clicked()
{
    ptrRemoveRecipe->show();
}

