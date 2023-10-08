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
    qDebug() << "~AddtoStorage()";
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


void AddToStorage::on_loadIngredientsButton_clicked()
{
    ui->existingIngredientsComboBox->clear();

    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);

    query.prepare("select IngredientName from Ingredient");
    query.exec();
    while(query.next())
    {
        ui->existingIngredientsComboBox->addItem(query.value(0).toString());
        qDebug() << "Filling Combobox " << query.value(0).toString();
    }

    qDebug() << "Last error : "<< query.lastQuery();
    qDebug() << "Last error : "<< query.lastError().text();
}



void AddToStorage::on_existingIngredientsComboBox_activated(int index)
{
    QString ingredientName = ui->existingIngredientsComboBox->currentText();
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);

    query.prepare("select IngredientName from Ingredient where IngredientName = '" + ingredientName + "'");
    query.exec();
    query.next();
    ui->ingredientNameLineEdit->setText(query.value(0).toString());
    query.finish();
    query.clear();
    qDebug() << "last error: " << query.lastQuery();
    qDebug() << "last error: " << query.lastError().text();
    query.prepare("select IngredientQuantity from Ingredient where IngredientName = '" + ingredientName + "'");
    query.exec();
    query.next();
    ui->quantityLineEdit->setText(query.value(0).toString());
    query.finish();
    query.clear();
    qDebug() << "last error: " << query.lastQuery();
    qDebug() << "last error: " << query.lastError().text();
    query.prepare("select IngredientExpiryDate from Ingredient where IngredientName = '" + ingredientName + "'");
    query.exec();
    query.next();
    ui->expiredDateLineEdit->setText(query.value(0).toString());
    query.finish();
    query.clear();
    qDebug() << "last error: " << query.lastQuery();
    qDebug() << "last error: " << query.lastError().text();
    query.prepare("select IngredientDescription from Ingredient where IngredientName = '" + ingredientName + "'");
    query.exec();
    query.next();
    ui->txtDescription->setText(query.value(0).toString());
    query.finish();
    query.clear();
    qDebug() << "last error: " << query.lastQuery();
    qDebug() << "last error: " << query.lastError().text();
}

