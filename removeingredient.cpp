#include "removeingredient.h"
#include "ui_removeingredient.h"

RemoveIngredient::RemoveIngredient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveIngredient)
{
    ui->setupUi(this);
}

RemoveIngredient::~RemoveIngredient()
{
    delete ui;
}

void RemoveIngredient::on_buttonBox_accepted()
{
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QString ingredientNameToDelete = ui->ingredientNameLineEdit->text();
    QString deleteQuery = "delete from Ingredient where IngredientName :name";
    QSqlQuery query(database);
    query.bindValue(":name", ingredientNameToDelete);
    query.prepare(deleteQuery);
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
}

