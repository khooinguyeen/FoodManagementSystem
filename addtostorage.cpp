#include "addtostorage.h"
#include "ui_addtostorage.h"

AddToStorage::AddToStorage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToStorage)
{
    ui->setupUi(this);
}

AddToStorage::~AddToStorage()
{
    delete ui;
}

void AddToStorage::on_btnReset_clicked()
{
    ui->ingredientNameLineEdit->clear();
    ui->quantityLineEdit->clear();
    ui->expiredDateLineEdit->clear();
    ui->txtDescription->clear();
}


void AddToStorage::on_btnSave_clicked()
{
    QString ingredientName = ui->ingredientNameLineEdit->text();
    QString ingredientQuantity = ui->quantityLineEdit->text();
    QString ingredientExpiredDate = ui->expiredDateLineEdit->text();
    QString ingredientDescription = ui->txtDescription->toPlainText();
    qDebug() << "Ingredient Name: " << ingredientName
             << " Ingredient Quantity: " << ingredientQuantity
             << " Ingredient Expiry Date: " << ingredientExpiredDate
             << " Ingredient Description: " << ingredientDescription;
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("insert into Storage (IngredientName, Quantity, ExpiredDate, Description) "
                  "values('" + ingredientName + "','" + ingredientQuantity + "','" + ingredientExpiredDate + "','" + ingredientDescription + "')");
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    on_btnReset_clicked();
}

