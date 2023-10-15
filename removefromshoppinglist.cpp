#include "removefromshoppinglist.h"
#include "ui_removefromshoppinglist.h"
#include <QMessageBox>

RemoveFromShoppingList::RemoveFromShoppingList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveFromShoppingList)
{
    ui->setupUi(this);
    // initialize database
    database = QSqlDatabase::database("DB0");
    // combo box will be implemeted right after the window open
    loadComboBox();
}

RemoveFromShoppingList::~RemoveFromShoppingList()
{
    qDebug() << "~RemoveFromShoppingList";
    delete ui;
}

void RemoveFromShoppingList::loadComboBox()
{
    // retrieve ingredient name from ShoppingList database
    QSqlQuery query(database);
    query.prepare("select IngredientName from ShoppingList");
    query.exec();
    while(query.next()){
        // show on combo box
        ui->cmbRemove->addItem(query.value(0).toString());
        qDebug() << "Filling cmbRemove" << query.value(0).toString();
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}

void RemoveFromShoppingList::on_buttonBox_accepted()
{
    // query method to delete choosen ingredient from combo box
    QString ingredientNameToRemove = ui->cmbRemove->currentText();
    QString deleteQuery = "delete from ShoppingList where IngredientName = :name";
    QSqlQuery query(database);
    query.prepare(deleteQuery);
    query.bindValue(":name", ingredientNameToRemove);
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Error: " << query.lastError().text();
    QMessageBox::information(this,"Success", "Remove successfully!");
}

