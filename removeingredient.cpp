#include "removeingredient.h"
#include "ui_removeingredient.h"

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
    QString ingredientNameToDelete = ui->ingredientNameLineEdit->text();
    QString deleteQuery = "delete from Ingredient where IngredientName like '%" + ingredientNameToDelete + "%'";
    QSqlQuery query(database);
    query.prepare(deleteQuery);
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
}

