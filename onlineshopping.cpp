#include "onlineshopping.h"

OnlineShopping::OnlineShopping(QWidget* parent) : ShoppingList(parent){

}

void OnlineShopping::loadAllElements() {
    ui->listWidget->clear();
    qDebug() << "load in ShoppingList";
    // query method to only retrieve ingredient with links
    QSqlQuery query(database);
    query.prepare("select IngredientName from ShoppingList where OnlineShoppingLink is not null and OnlineShoppingLink != ''");
    query.exec();
    while(query.next()){
        // show ingredient on the list widget
        QString ingredientName = query.value(0).toString();
        QListWidgetItem *newItem = new QListWidgetItem(ingredientName);
        ui->listWidget->addItem(newItem);
    }
}

void OnlineShopping::showLink() {
    ui->txtInfo->clear();
    QString selectedIngredient = ui->listWidget->currentItem()->text();
    ui->txtInfo->append(selectedIngredient);
    // query method to retrieve the choosen ingredient info
    QSqlQuery query(database);
    query.prepare("select OnlineShoppingLink from ShoppingList where IngredientName = :name");
    query.bindValue(":name", selectedIngredient);
    query.exec();
    while(query.next()){
        // show ingredient info only with links
        QString link = query.value(0).toString();
        ui->txtInfo->append("Online shopping link: " + link);
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}

void OnlineShopping::showInfo() {
    showLink();
}
