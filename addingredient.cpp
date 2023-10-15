#include "addingredient.h"
#include "ui_addingredient.h"
#include <QMessageBox>

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
    if (validateUserInput() == false) {
        return;
    }
    // Initialize the values to the inputs from the LineEdit in Ui
    QString ingredientName = ui->ingredientNameLineEdit->text();
    QString ingredientDescription = ui->txtDescription->toPlainText();

    // Log all the value to terminal to check
    qDebug() << "Ingredient Name: " << ingredientName
             << " Ingredient Description: " << ingredientDescription;

    QSqlDatabase database = QSqlDatabase::database("DB0");
    // Insert the value to database
    QSqlQuery query(database);
    query.prepare("insert into Ingredient (IngredientName, Description) "
                  "values('" + ingredientName + "','" + ingredientDescription + "')");
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    QMessageBox::information(this, "Success", "Added succesfully!");
    // Reset the input after finished adding new ingredient
    on_btnReset_clicked();

}

void AddIngredient::on_btnReset_clicked()
{
    // Clear the input of LineEdit
    ui->ingredientNameLineEdit->clear();
    ui->txtDescription->clear();
}

bool AddIngredient::validateUserInput() {
    QString ingredientName = ui->ingredientNameLineEdit->text();
    // check if ingredient name is void
    if (ingredientName.isEmpty()) {
        QMessageBox::critical(this, "Validation Error", "Input cannot be empty.");
        return false;
    }
    // check if ingredient name already exists
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("select IngredientName from Ingredient");
    query.exec();
    while(query.next()) {
        QString existedIngredientName = query.value(0).toString();
        if (ingredientName == existedIngredientName) {
            QMessageBox::critical(this,"Validation Error", "Name already exist!");
            query.finish();
            query.clear();
            qDebug() << "Last error: " << query.lastError().text();
            return false;
        }
    }
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    return true;
}




