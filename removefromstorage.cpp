#include "removefromstorage.h"
#include "ui_removefromstorage.h"
#include "databaseheader.h"

RemoveFromStorage::RemoveFromStorage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveFromStorage)
{
    ui->setupUi(this);
}

RemoveFromStorage::~RemoveFromStorage()
{
    delete ui;
}

void RemoveFromStorage::on_acceptButton_clicked()
{
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QString ingredientNameToDelete = ui->ingredientNamelineEdit->text();
    QString deleteQuery = "delete from Storage where IngredientName like '%" + ingredientNameToDelete + "%'";
    QSqlQuery query(database);
    query.prepare(deleteQuery);
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    on_cancelButton_clicked();
}



void RemoveFromStorage::on_cancelButton_clicked()
{
    ui->ingredientNamelineEdit->clear();
}

