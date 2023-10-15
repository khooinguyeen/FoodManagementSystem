#include "addtostorage.h"
#include "ui_addtostorage.h"
#include <QMessageBox>

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
    query.prepare("Select IngredientName from Ingredient where IngredientName like '%" + ingredientName +"'");
    query.exec();
    // retrieve choosen ingredient information from Ingredient database and assign to the correspond line
    if(query.next()) {
        ui->ingredientNameLineEdit->setText(query.value(0).toString());
        qDebug() << "Ingredient name line edited: " << query.value(0).toString();
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}


void AddToStorage::on_btnOk_clicked()
{
    if (validateUserInput() == false) {
        return;
    }
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
    QMessageBox::information(this, "Success", "Added succesfully!");
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

bool AddToStorage::validateUserInput() {
    QString ingredientName = ui->ingredientNameLineEdit->text();
    QString quantity = ui->quantityLineEdit->text();
    QString expiredDate = ui->expiredLineEdit->text();
    // check if ingredient name is void
    if (ingredientName == "") {
        QMessageBox::critical(this, "Error", "Ingredient name cannot be void!");
        return false;
    }
    // check if ingredient name is already taken
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("select IngredientName from Storage");
    query.exec();
    while(query.next()) {
        QString existedIngredientName = query.value(0).toString();
        if (ingredientName == existedIngredientName) {
            QMessageBox::critical(this, "Error", "Name already existed!");
            query.finish();
            query.clear();
            qDebug() << "Last error: " << query.lastError().text();
            return false;
        }
    }
    // check if quantity is an positive integer
    // check if input character is digit or not
    for (const QChar&element : quantity) {
        if (!element.isDigit()) {
            QMessageBox::critical(this, "Error", "Input can only be a positive integer!");
            return false;
        }
    }
    // check if input is not empty, is an positive intger and the first character is not 0
    if (quantity.isEmpty() || quantity.toInt() <= 0 || quantity[0] == '0') {
        QMessageBox::critical(this, "Error", "Input can only be a positive integer!");
        return false;
    }
    // check if expired date is the right format dd/mm/yy
    static QRegularExpression regex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/(20\\d{2}|21\\d{2})$");
    if (!regex.match(expiredDate).hasMatch()) {
        QMessageBox::critical(this, "Error", "Expired date format must be dd//mm//year");
        return false;
    }
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    return true;
}

