#include "addtoshoppinglist.h"
#include "ui_addtoshoppinglist.h"
#include <QMessageBox>

void AddToShoppingList::loadComboBox()
{
    ui->ingredientComboBox->clear();
    // initialize database and query method to retrieve data from the database
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    // retrieve ingredient name from Ingredient Storage
    query.prepare("select IngredientName from Ingredient");
    query.exec();
    while(query.next()) {
        // show ingredient name on the combo box
        ui->ingredientComboBox->addItem(query.value(0).toString());
        qDebug() << "filling combo box: " << query.value(0).toString();
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}

AddToShoppingList::AddToShoppingList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToShoppingList)
{
    ui->setupUi(this);
    loadComboBox();
}

AddToShoppingList::~AddToShoppingList()
{
    qDebug() << "~AddToShoppingList()";
    delete ui;
}

void AddToShoppingList::on_buttonBox_accepted()
{
    if (validateUserInput() == false) {
        return;
    }
    // initialize database and query method to retrieve data from the database
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QString ingredientName = ui->ingredientComboBox->currentText();
    QString note = ui->noteLineEdit->text();
    QString link = ui->onlineShoppingLinkLineEdit->text();
    QString marketName = ui->marketNameLineEdit->text();
    QString phoneNumber = ui->phoneNumberLineEdit->text();
    QString location = ui->locationLineEdit->text();
    // add new ingredient into the Shoppinglist database
    QString addQuery = "insert into ShoppingList (IngredientName, Note, OnlineShoppingLink, MarketName, PhoneNumber, Location) "
                       "values('" + ingredientName + "','" + note + "','" + link + "','" + marketName + "','" + phoneNumber + "','" + location + "')";
    qDebug() << ingredientName << note << link << marketName << phoneNumber << location;
    QSqlQuery query(database);
    query.prepare(addQuery);
    query.exec();
    query.finish();
    query.clear();
    QMessageBox::critical(this, "Success", "Added successfully!");
    qDebug() << "Last error: " << query.lastError().text();
    ui->noteLineEdit->clear();
    ui->onlineShoppingLinkLineEdit->clear();
    ui->marketNameLineEdit->clear();
    ui->phoneNumberLineEdit->clear();
    ui->locationLineEdit->clear();
}

bool AddToShoppingList::validateUserInput() {
    QString ingredientName = ui->ingredientComboBox->currentText();
    // check if name already exist
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("select IngredientName from ShoppingList");
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
    return true;
}

