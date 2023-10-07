#include "storage.h"
#include "ui_storage.h"

Storage::Storage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Storage)
{
    ui->setupUi(this);

    loadAllElements();

    ptrAddToStorage = new AddToStorage();
    ptrRemoveFromStorage = new RemoveFromStorage();
    model = new QSqlQueryModel();

}

Storage::~Storage()
{
    qDebug() << "~Storage";
    delete ui;
    delete ptrAddToStorage;
    delete ptrRemoveFromStorage;
    delete model;
}

void Storage::loadAllElements()
{
    QSqlDatabase database = QSqlDatabase::database("DB0");
    if (model == nullptr) {
        model = new QSqlQueryModel();
    }
    model->setQuery("Select * From Storage", database);
    ui->tableView->setModel(model);
}


void Storage::on_listItemButton_clicked()
{
    QString ingredientName = ui->txtIngredient->text();
    qDebug() << "Ingredient name: "<< ingredientName;
    QSqlDatabase database = QSqlDatabase::database("DB0");

    if(model == nullptr) {
        model = new QSqlQueryModel();
    }

    if(ingredientName.isEmpty()) {
        loadAllElements();
    }
    else {
        model->setQuery("select * from Storage where IngredientName like '%" + ingredientName + "%'", database);
        ui->tableView->setModel(model);
    }

}


void Storage::on_addButton_clicked()
{
    ptrAddToStorage->show();
}


void Storage::on_removeButton_clicked()
{
    ptrRemoveFromStorage->show();
}

