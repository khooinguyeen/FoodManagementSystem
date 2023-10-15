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
    // Initialize the values to the inputs from the LineEdit in Ui
    QString ingredientName = ui->ingredientNameLineEdit->text();
    QString ingredientQuantity = ui->quantityLineEdit->text();
    QString ingredientExpiryDate = ui->expiryDateLineEdit->text();
    QString ingredientDescription = ui->txtDescription->toPlainText();

    // Log all the value to terminal to check
    qDebug() << "Ingredient Name: " << ingredientName
             << " Ingredient Quantity: " << ingredientQuantity
             << " Ingredient Expiry Date: " << ingredientExpiryDate
             << " Ingredient Description: " << ingredientDescription;

    QSqlDatabase database = QSqlDatabase::database("DB0");
    // Insert the value to database
    QSqlQuery query(database);
    query.prepare("insert into Ingredient (IngredientName, IngredientQuantity, IngredientExpiryDate, IngredientDescription) "
                  "values('" + ingredientName + "','" + ingredientQuantity + "','" + ingredientExpiryDate + "','" + ingredientDescription + "')");
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();

    // Reset the input after finished adding new ingredient
    on_btnReset_clicked();

}

void AddIngredient::on_btnReset_clicked()
{
    // Clear the input of LineEdit
    ui->ingredientNameLineEdit->clear();
    ui->quantityLineEdit->clear();
    ui->expiryDateLineEdit->clear();
    ui->txtDescription->clear();
}




