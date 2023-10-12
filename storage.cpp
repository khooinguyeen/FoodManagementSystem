#include "storage.h"
#include "ui_list.h"
#include "addtostorage.h"
#include <QMessageBox>

Storage::Storage() : List(){
    loadAllElements();
}

void Storage::addIngredient(){
    qDebug() << "add to Storage";
    ptrAddToStorage = new AddToStorage();
    ptrAddToStorage->show();
    loadAllElements();
}


void Storage::removeIngredient(){
    qDebug() << "remove from Storage";
    ptrRemoveFromStorage = new RemoveFromStorage();
    ptrRemoveFromStorage->show();

    /*if (currentItem == nullptr) {
        QMessageBox::warning(this, "Error","Select an ingredient on the list.");
    }
    else {
        QString ingredientName = currentItem->text();
        QMessageBox::question(this, "Remove ingredient",
                              "Do you want to remove " + ingredientName + " ?",
                              QMessageBox::Yes | QMessageBox::No);
    }*/
    loadAllElements();
}
void Storage::loadAllElements(){
    ui->listWidget->clear();
    qDebug() << "load all in Storage ";
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("Select IngredientName from Storage");
    query.exec();
    while(query.next()) {
        ui->listWidget->addItem(query.value(0).toString());
        qDebug() << "Filling listWidget" << query.value(0).toString();
    }

}
void Storage::showInfo(){
    ui->txtIngredientInfo->clear();
    qDebug() << "show ingredient info on the widget list in Storage";
    QString ingredientName = ui->listWidget->currentItem()->text();
    qDebug() << "item clicked: " << ingredientName;
    ui->txtIngredientInfo->append("INGREDIENT INFORMATION");
    ui->txtIngredientInfo->append("\n");
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("Select ID, IngredientName, Quantity, ExpiredDate from Storage where IngredientName = :name");
    query.bindValue(":name", ingredientName);
    query.exec();
    if (query.next()) {
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString quantity = query.value(2).toString();
        QString expiredDate = query.value(3).toString();
        ui->txtIngredientInfo->append("ID: " + id);
        ui->txtIngredientInfo->append("Ingredient name: " + name);
        ui->txtIngredientInfo->append("Quantity: " + quantity);
        ui->txtIngredientInfo->append("Expired date: " + expiredDate);
        qDebug() << query.lastQuery();
        qDebug() << query.lastError().text();
    }
    loadAllElements();
}

Storage::~Storage() {
    delete ptrAddToStorage;
    delete ptrRemoveFromStorage;
}
