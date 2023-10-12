#include "addtoshoppinglist.h"
#include "ui_addtoshoppinglist.h"

void AddToShoppingList::loadComboBox()
{
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);

    query.prepare("select IngredientName from Ingredient");
    query.exec();
    while(query.next()) {
        ui->ingredientComboBox->addItem(query.value(0).toString());
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
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QString ingredientName = ui->ingredientComboBox->currentText();
    QString note = ui->noteLineEdit->text();
    QString link = ui->onlineShoppingLinkLineEdit->text();
    QString marketName = ui->marketNameLineEdit->text();
    QString phoneNumber = ui->phoneNumberLineEdit->text();
    QString location = ui->locationLineEdit->text();
    QString addQuery = "insert into ShoppingList (IngredientName, Note, OnlineShoppingLink, MarketName, PhoneNumber, Location) "
                       "values('" + ingredientName + "','" + note + "','" + link + "','" + marketName + "','" + phoneNumber + "','" + location + "')";
    qDebug() << ingredientName << note << link << marketName << phoneNumber << location;
    QSqlQuery query(database);
    query.prepare(addQuery);
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
}

