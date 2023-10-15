#include "shoppinglist.h"

ShoppingList::ShoppingList(QWidget *parent) : List(parent){
    ptrAddToShoppingList = new AddToShoppingList();
    ptrRemoveFromShoppingList = new RemoveFromShoppingList();
}

void ShoppingList::addIngredient(){
    qDebug() << "add to ShoppingList";
    // open window to add ingredient
    ptrAddToShoppingList->show();

}
void ShoppingList::removeIngredient(){
    qDebug() << "remove from ShoppingList";
    // open window to remove ingredient
    ptrRemoveFromShoppingList->show();
}
void ShoppingList::loadAllElements(){

    ui->listWidget->clear();
    qDebug() << "load in ShoppingList";
    // retrieve all ingredient name from Shoppinglist database
    QSqlQuery query(database);
    query.prepare("select IngredientName from ShoppingList");
    query.exec();
    while(query.next()){
        // show on the list widget
        QString ingredientName = query.value(0).toString();
        ui->listWidget->addItem(ingredientName);
    }
}

ShoppingList::~ShoppingList(){
    qDebug() << "~Shoppinglist()";
    delete ptrAddToShoppingList;
    delete ptrRemoveFromShoppingList;
}

void ShoppingList::showInfo(){
    ui->txtInfo->clear();
    QString selectedIngredient = ui->listWidget->currentItem()->text();
    ui->txtInfo->append(selectedIngredient);
    // retrieve choosen ingredient data from ShoppingList database
    QSqlQuery query(database);
    query.prepare("select MarketName, PhoneNumber, Location from ShoppingList where IngredientName like '%" + selectedIngredient + "%'");
    query.exec();
    while(query.next()){
        QString marketName = query.value(0).toString();
        QString phoneNumeber = query.value(1).toString();
        QString location = query.value(2).toString();
        // show ingredient info on the text box
        ui->txtInfo->append("Market Name: " + marketName);
        ui->txtInfo->append("Phone Number: " + phoneNumeber);
        ui->txtInfo->append("Location: " + location);
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}
