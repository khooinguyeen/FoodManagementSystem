#include "onlineshopping.h"

OnlineShopping::OnlineShopping(QWidget* parent) : ShoppingList(parent){

}

void OnlineShopping::loadAllElements() {
    ui->listWidget->clear();
    qDebug() << "load in ShoppingList";
    QSqlQuery query(database);
    query.prepare("select IngredientName from ShoppingList where OnlineShoppingLink is not null and OnlineShoppingLink != ''");
    query.exec();
    while(query.next()){
        QString ingredientName = query.value(0).toString();
        QListWidgetItem *newItem = new QListWidgetItem(ingredientName);
        ui->listWidget->addItem(newItem);
    }
}

void OnlineShopping::showLink() {
    ui->txtInfo->clear();
    QString selectedIngredient = ui->listWidget->currentItem()->text();
    ui->txtInfo->append(selectedIngredient);
    QSqlQuery query(database);
    query.prepare("select OnlineShoppingLink from ShoppingList where IngredientName = :name");
    query.bindValue(":name", selectedIngredient);
    query.exec();
    if(query.next()){
        QString link = query.value(0).toString();
        ui->txtInfo->append("Online shopping link: " + link);
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}

void OnlineShopping::showInfo() {
    showLink();
}
