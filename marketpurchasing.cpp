#include "marketpurchasing.h"

MarketPurchasing::MarketPurchasing(QWidget *parent) : ShoppingList(parent){}
void MarketPurchasing::loadAllElements(){
    qDebug() << "load in ShoppingList";
    QSqlQuery query(database);
    query.prepare("select IngredientName from ShoppingList where MarketName is not null");
    query.exec();
    while(query.next()){
        QString ingredientName = query.value(0).toString();
        QListWidgetItem *newItem = new QListWidgetItem(ingredientName);
        ui->listWidget->addItem(newItem);
    }
}

void MarketPurchasing::showMarketInfo(){
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

void MarketPurchasing::showInfo(){
    showMarketInfo();
}
