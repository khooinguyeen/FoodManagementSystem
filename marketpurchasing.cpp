#include "marketpurchasing.h"

MarketPurchasing::MarketPurchasing(QWidget *parent) : ShoppingList(parent){

}

void MarketPurchasing::loadAllElements(){
    ui->listWidget->clear();
    qDebug() << "load in ShoppingList";
    // query method to retrieve only ingredient with market infos
    QSqlQuery query(database);
    query.prepare("select IngredientName from ShoppingList where MarketName is not null and MarketName != ''");
    query.exec();
    while(query.next()){
        // show ingredient on the list widget
        QString ingredientName = query.value(0).toString();
        QListWidgetItem *newItem = new QListWidgetItem(ingredientName);
        ui->listWidget->addItem(newItem);
    }
}

void MarketPurchasing::showMarketInfo(){
    ui->txtInfo->clear();
    QString selectedIngredient = ui->listWidget->currentItem()->text();
    ui->txtInfo->append(selectedIngredient);
    // query method to retrive the choosen ingredient info, not include links
    QSqlQuery query(database);
    query.prepare("select MarketName, PhoneNumber, Location from ShoppingList where IngredientName = :name");
    query.bindValue(":name", selectedIngredient);
    query.exec();
    while(query.next()){
        // show ingredient info on the text box
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
