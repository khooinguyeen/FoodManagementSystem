#include "removeingredient.h"
#include "ui_removeingredient.h"
#include <QMessageBox>

RemoveIngredient::RemoveIngredient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveIngredient)
{
    ui->setupUi(this);
    // initialize database
    database = QSqlDatabase::database("DB0");
}

RemoveIngredient::~RemoveIngredient()
{
    qDebug() << "~RemoveIngredient()";
    delete ui;
}

void RemoveIngredient::loadComboBox()
{
    ui->cmbRemove->clear();
    // retrieve ingredient name from database
    QSqlQuery query(database);
    query.prepare("select IngredientName from Ingredient");
    query.exec();
    while(query.next()){
        // Show ingredient on combo box
        ui->cmbRemove->addItem(query.value(0).toString());
        qDebug() << "Filling cmbRemove" << query.value(0).toString();
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}

void RemoveIngredient::on_buttonBox_accepted()
{
    if (validateUserInput() == false) {
        return;
    }
    // query method to delete ingredient based on input name
    
    QString ingredientNameToDelete = ui->cmbRemove->currentText();
    QString deleteQuery = "delete from Ingredient where IngredientName = :name";
    QSqlQuery query(database);
    query.prepare(deleteQuery);
    query.bindValue(":name", ingredientNameToDelete);
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    QMessageBox::information(this, "Success", "Removed successfully!");
    ui->cmbRemove->clear();
}


void RemoveIngredient::on_btnLoad_clicked()
{
    loadComboBox();
}

bool RemoveIngredient::validateUserInput() {
    QString ingredientToDelete = ui->cmbRemove->currentText();
    // check if input is void
    if (ingredientToDelete.isEmpty()) {
        QMessageBox::warning(this, "Warning", "You are removing all ingredients!");
    }
    // check if no ingredient name match the input
    // check if no recipe name match the input
    QSqlQuery query(database);
    query.prepare("select IngredientName from Ingredient");
    query.exec();
    while(query.next()) {
        QString existedRecipeName = query.value(0).toString();
        if (ingredientToDelete == existedRecipeName) {
            return true;
        }
    }
    QMessageBox::critical(this, "Error", "No ingredients'names matched your input!");
    return false;
}
