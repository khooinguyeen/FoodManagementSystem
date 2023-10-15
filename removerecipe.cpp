#include "removerecipe.h"
#include "ui_removerecipe.h"
#include <QMessageBox>

RemoveRecipe::RemoveRecipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveRecipe)
{
    ui->setupUi(this);
}

RemoveRecipe::~RemoveRecipe()
{
    qDebug() << "~RemoveRecipe()";
    delete ui;
}

void RemoveRecipe::on_buttonBox_accepted()
{
    if (validateUserInput() == false) {
        return;
    }
    // Delete the recipe with the name typed from the database
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QString recipeNameToDelete = ui->recipeNameLineEdit->text();
    QString deleteQuery = "delete from Recipe where RecipeName = :name";
    QSqlQuery query(database);
    query.prepare(deleteQuery);
    query.bindValue(":name", recipeNameToDelete);
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    QMessageBox::information(this, "Success", "Remove successfully!");
    ui->recipeNameLineEdit->clear();
}

bool RemoveRecipe::validateUserInput() {
    QString recipeToDelete = ui->recipeNameLineEdit->text();
    // check if input is void
    if (recipeToDelete.isEmpty()) {
        QMessageBox::warning(this, "Warning", "You are removing all recipes!");
        return true;
    }
    // check if no recipe name match the input
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("select RecipeName from Recipe");
    query.exec();
    while(query.next()) {
        QString existedRecipeName = query.value(0).toString();
        if (recipeToDelete == existedRecipeName) {
            return true;
        }
    }
    QMessageBox::critical(this, "Error", "No recipes'names matched your input!");
    return false;
}

