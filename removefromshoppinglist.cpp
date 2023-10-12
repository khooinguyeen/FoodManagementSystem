#include "removefromshoppinglist.h"
#include "ui_removefromshoppinglist.h"

RemoveFromShoppingList::RemoveFromShoppingList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveFromShoppingList)
{
    ui->setupUi(this);
    database = QSqlDatabase::database("DB0");
    loadComboBox();
}

RemoveFromShoppingList::~RemoveFromShoppingList()
{
    delete ui;
}

void RemoveFromShoppingList::loadComboBox()
{
    QSqlQuery query(database);
    query.prepare("select IngredientName from ShoppingList");
    query.exec();
    while(query.next()){
        ui->cmbRemove->addItem(query.value(0).toString());
        qDebug() << "Filling cmbRemove" << query.value(0).toString();
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}

void RemoveFromShoppingList::on_buttonBox_accepted()
{
    QString ingredientNameToRemove = ui->cmbRemove->currentText();
    QString deleteQuery = "delete from ShoppingList where IngredientName like '%" + ingredientNameToRemove + "%'";
    QSqlQuery query(database);
    query.prepare(deleteQuery);
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Error: " << query.lastError().text();
}

