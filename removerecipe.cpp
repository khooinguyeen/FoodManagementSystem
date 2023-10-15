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
    delete ui;
}

void RemoveRecipe::on_buttonBox_accepted()
{
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

