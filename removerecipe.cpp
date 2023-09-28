#include "removerecipe.h"
#include "ui_removerecipe.h"

RemoveRecipe::RemoveRecipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveRecipe)
{
    ui->setupUi(this);
}

RemoveRecipe::~RemoveRecipe()
{
    delete ui;
}
