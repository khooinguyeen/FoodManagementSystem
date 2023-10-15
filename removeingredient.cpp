#include "removeingredient.h"
#include "ui_removeingredient.h"
#include <QMessageBox>

RemoveIngredient::RemoveIngredient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveIngredient)
{
    ui->setupUi(this);
    database = QSqlDatabase::database("DB0");
}

RemoveIngredient::~RemoveIngredient()
{
    delete ui;
}

void RemoveIngredient::on_buttonBox_accepted()
{
    if (validateUserInput() == false) {
        return;
    }
    QString ingredientNameToDelete = ui->ingredientNameLineEdit->text();
    QString deleteQuery = "delete from Ingredient where IngredientName = :name";
    QSqlQuery query(database);
    query.prepare(deleteQuery);
    query.bindValue(":name", ingredientNameToDelete);
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    QMessageBox::information(this, "Success", "Remove successfully!");
    ui->ingredientNameLineEdit->clear();
}

bool RemoveIngredient::validateUserInput() {
    QString ingredientToDelete = ui->ingredientNameLineEdit->text();
    // check if input is void
    if (ingredientToDelete.isEmpty()) {
        QMessageBox::warning(this, "Warning", "You are removing all ingredients!");
    }
    // check if no ingredient name match the input
    // check if no recipe name match the input
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("select IngredientName from Ingredient");
    query.exec();
    while(query.next()) {
        QString existedRecipeName = query.value(0).toString();
        if (ingredientToDelete == existedRecipeName) {
            return true;
        }
    }
    QMessageBox::critical(this, "Error", "No ingredients'names matched your input!");
    return false;
}
