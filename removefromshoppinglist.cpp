#include "removefromshoppinglist.h"
#include "ui_removefromshoppinglist.h"

RemoveFromShoppingList::RemoveFromShoppingList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveFromShoppingList)
{
    ui->setupUi(this);
}

RemoveFromShoppingList::~RemoveFromShoppingList()
{
    delete ui;
}
