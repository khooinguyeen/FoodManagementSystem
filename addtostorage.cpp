#include "addtostorage.h"
#include "ui_addtostorage.h"

AddToStorage::AddToStorage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToStorage)
{
    ui->setupUi(this);
}

AddToStorage::~AddToStorage()
{
    qDebug() << "~AddToStorage";
    delete ui;
}

void AddToStorage::on_cbxloadIngredients_activated(int index)
{
    on_btnReset_clicked();
    // initialize database and query method to retrieve data from the database
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    QString ingredientName = ui->cbxloadIngredients->currentText();
    query.prepare("Select IngredientName, Quantity from Ingredient where IngredientName like '%" + ingredientName +"'");
    query.exec();
    // retrieve choosen ingredient information from Ingredient database and assign to the correspond line
    if(query.next()) {
        ui->ingredientNameLineEdit->setText(query.value(0).toString());
        qDebug() << "Ingredient name line edited: " << query.value(0).toString();
        ui->quantityLineEdit->setText(query.value(1).toString());
        qDebug() << "Ingredient name line edited: " << query.value(1).toString();
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}


void AddToStorage::on_btnOk_clicked()
{
    QString ingredientName = ui->ingredientNameLineEdit->text();
    QString quantity = ui->quantityLineEdit->text();
    QString expiredDate = ui->expiredLineEdit->text();
    qDebug() << " Edited Ingredient name: " << ingredientName
             << "Edited Quantity: " << quantity
             << "Edited Expired date: " << expiredDate;
    // initialize database and query method to retrieve data from the database
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    // store added ingredient into the Storage database
    query.prepare("insert into Storage (IngredientName, Quantity, ExpiredDate) "
                  "values('" + ingredientName + "','" + quantity + "','" + expiredDate + "')");
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    on_btnReset_clicked();
}


void AddToStorage::on_btnReset_clicked()
{
    // clear up all edited information on the screen
    ui->ingredientNameLineEdit->clear();
    ui->quantityLineEdit->clear();
    ui->expiredLineEdit->clear();
    ui->cbxloadIngredients->clear();
}


void AddToStorage::on_btnLoadIngredients_clicked()
{
    ui->cbxloadIngredients->clear();
    // initialize database and query method to retrieve data from the database
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("Select IngredientName from Ingredient");
    query.exec();
    while(query.next()) {
        ui->cbxloadIngredients->addItem(query.value(0).toString());
        qDebug() << "Filling ComboBox: " << query.value(0).toString();
    }
}

