#include "addingredient.h"
#include "ui_addingredient.h"
AddIngredient::AddIngredient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddIngredient)
{
    ui->setupUi(this);
}

AddIngredient::~AddIngredient()
{
    qDebug() << "~AddIngredient()";
    delete ui;
}

void AddIngredient::on_btnSave_clicked()
{
    QString ingredientName = ui->ingredientNameLineEdit->text();
    QString ingredientQuantity = ui->quantityLineEdit->text();
    QString ingredientExpiryDate = ui->expiryDateLineEdit->text();
    QString ingredientDescription = ui->txtDescription->toPlainText();
    qDebug() << "Ingredient Name: " << ingredientName
             << " Ingredient Quantity: " << ingredientQuantity
             << " Ingredient Expiry Date: " << ingredientExpiryDate
             << " Ingredient Description: " << ingredientDescription;
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("insert into Ingredient (IngredientName, IngredientQuantity, IngredientExpiryDate, IngredientDescription) "
                  "values('" + ingredientName + "','" + ingredientQuantity + "','" + ingredientExpiryDate + "','" + ingredientDescription + "')");
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    on_btnReset_clicked();

}

void AddIngredient::on_btnReset_clicked()
{
    ui->ingredientNameLineEdit->clear();
    ui->quantityLineEdit->clear();
    ui->expiryDateLineEdit->clear();
    ui->txtDescription->clear();
}




