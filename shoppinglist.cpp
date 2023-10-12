#include "shoppinglist.h"

ShoppingList::ShoppingList(QWidget *parent) : List(parent){
    ptrAddToShoppingList = new AddToShoppingList();
    ptrRemoveFromShoppingList = new RemoveFromShoppingList();
}

void ShoppingList::addIngredient(){
    qDebug() << "add to ShoppingList";
    ptrAddToShoppingList->show();

}
void ShoppingList::removeIngredient(){
    qDebug() << "remove from ShoppingList";
    ptrRemoveFromShoppingList->show();
}
void ShoppingList::loadAllElements(){
    qDebug() << "load in ShoppingList";
    QSqlQuery query(database);
    query.prepare("select IngredientName from ShoppingList");
    query.exec();
    while(query.next()){
        QString ingredientName = query.value(0).toString();
        ui->listWidget->addItem(ingredientName);
    }
}

ShoppingList::~ShoppingList(){
    delete ptrAddToShoppingList;
    delete ptrRemoveFromShoppingList;
}

void ShoppingList::showInfo(){
    QString selectedIngredient = ui->listWidget->currentItem()->text();
    ui->txtInfo->append(selectedIngredient);
    QSqlQuery query(database);
    query.prepare("select MarketName, PhoneNumber, Location from ShoppingList where IngredientName like '%" + selectedIngredient + "%'");
    query.exec();
    while(query.next()){
        QString marketName = query.value(0).toString();
        QString phoneNumeber = query.value(1).toString();
        QString location = query.value(2).toString();
        ui->txtInfo->append("Market Name: " + marketName);
        ui->txtInfo->append("Phone Number: " + phoneNumeber);
        ui->txtInfo->append("Location: " + location);
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}
