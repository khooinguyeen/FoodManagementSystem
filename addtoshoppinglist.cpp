#include "addtoshoppinglist.h"
#include "ui_addtoshoppinglist.h"

AddToShoppingList::AddToShoppingList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToShoppingList)
{
    ui->setupUi(this);
}

AddToShoppingList::~AddToShoppingList()
{
    delete ui;
}
