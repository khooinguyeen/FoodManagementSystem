#include "storage.h"
#include "ui_list.h"
#include "addtostorage.h"

Storage::Storage(QWidget *parent) : List(parent){

}

void Storage::addIngredient(){
    qDebug() << "add to Storage";
    // initialize the pointer to ui for AddToStorage class
    ptrAddToStorage = new AddToStorage();
    ptrAddToStorage->setWindowTitle("Add");
    ptrAddToStorage->show();
    loadAllElements();
}


void Storage::removeIngredient(){
    qDebug() << "remove from Storage";
    // initialize the pointer to ui for RemoveFromStorage class
    ptrRemoveFromStorage = new RemoveFromStorage();
    ptrRemoveFromStorage->setWindowTitle("Remove");
    ptrRemoveFromStorage->show();
    loadAllElements();
}
void Storage::loadAllElements(){
    ui->listWidget->clear();
    qDebug() << "load all in Storage ";
    // initialize database and query method to retrieve data from the database
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    // retrieve all ingredient name from the database
    query.prepare("Select IngredientName from Storage");
    query.exec();
    while(query.next()) {
        // show ingredient name on list widget
        ui->listWidget->addItem(query.value(0).toString());
        qDebug() << "Filling listWidget" << query.value(0).toString();
    }

}
void Storage::showInfo(){
    ui->txtInfo->clear();
    qDebug() << "show ingredient info on the widget list in Storage";
    QString ingredientName = ui->listWidget->currentItem()->text();
    qDebug() << "item clicked: " << ingredientName;
    ui->txtInfo->append("INGREDIENT INFORMATION");
    ui->txtInfo->append("\n");
    // initialize database and query method to retrieve data from the database
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    // prepare query to retrieve the choosen ingredient info from database
    query.prepare("Select ID, IngredientName, Quantity, ExpiredDate from Storage where IngredientName = :name");
    query.bindValue(":name", ingredientName);
    query.exec();
    if (query.next()) {
        QString id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString quantity = query.value(2).toString();
        QString expiredDate = query.value(3).toString();
        // show ingredient info on the text box
        ui->txtInfo->append("ID: " + id);
        ui->txtInfo->append("Ingredient name: " + name);
        ui->txtInfo->append("Quantity: " + quantity);
        ui->txtInfo->append("Expired date: " + expiredDate);
        qDebug() << query.lastQuery();
        qDebug() << query.lastError().text();
    }
    loadAllElements();
}

Storage::~Storage() {
    qDebug() << "~Storage" ;
    delete ptrAddToStorage;
    delete ptrRemoveFromStorage;
}
