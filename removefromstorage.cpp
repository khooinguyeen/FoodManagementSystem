#include "removefromstorage.h"
#include "ui_removefromstorage.h"

RemoveFromStorage::RemoveFromStorage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RemoveFromStorage)
{
    ui->setupUi(this);
}

RemoveFromStorage::~RemoveFromStorage()
{
    qDebug() << "~RemoveFromStorage";
    delete ui;
}

void RemoveFromStorage::on_cbxRemoveIngredient_activated(int index)
{

}


void RemoveFromStorage::on_btnOk_clicked()
{
    // initialize database and query method to retrieve data from the database
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QString ingredientNameToDelete = ui->cbxRemoveIngredient->currentText();
    // query to delete the choosen ingredient ingredient on the combo box from the Storage database
    QString deleteQuery = "delete from Storage where IngredientName = :name";
    QSqlQuery query(database);
    query.prepare(deleteQuery);
    query.bindValue(":name", ingredientNameToDelete);
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    ui->cbxRemoveIngredient->clear();
}


void RemoveFromStorage::on_btnCancel_clicked()
{
    ui->cbxRemoveIngredient->clear();
}


void RemoveFromStorage::on_btnLoadStorage_clicked()
{
    ui->cbxRemoveIngredient->clear();
    // initialize database and query method to retrieve data from the database
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("Select IngredientName from Storage");
    query.exec();
    while(query.next()) {
        // show all ingredient in Storage database on the combo box
        ui->cbxRemoveIngredient->addItem(query.value(0).toString());
        qDebug() << "Filling ComboBox: " << query.value(0).toString();
    }
}

