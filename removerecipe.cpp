#include "removerecipe.h"
#include "ui_removerecipe.h"

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
    // Delte the recipe with the name typed from the database
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
    ui->recipeNameLineEdit->clear();
}

