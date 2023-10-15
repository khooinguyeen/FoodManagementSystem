#include "removerecipe.h"
#include "ui_removerecipe.h"
#include <QMessageBox>

RemoveRecipe::RemoveRecipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveRecipe)
{
    ui->setupUi(this);
    database = QSqlDatabase::database("DB0");
}

RemoveRecipe::~RemoveRecipe()
{
    qDebug() << "~RemoveRecipe()";
    delete ui;
}

void RemoveRecipe::on_buttonBox_accepted()
{
    if (validateUserInput() == false) {
        return;
    }
    // Delete the recipe with the name typed from the database
    QString recipeNameToDelete = ui->cmbRemove->currentText();
    QString deleteQuery = "delete from Recipe where RecipeName = :name";
    QSqlQuery query(database);
    query.prepare(deleteQuery);
    query.bindValue(":name", recipeNameToDelete);
    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    QMessageBox::information(this, "Success", "Removed successfully!");
    ui->cmbRemove->clear();
}

void RemoveRecipe::loadComboBox()
{
    ui->cmbRemove->clear();
    // retrieve recipe name from database
    QSqlQuery query(database);
    query.prepare("select RecipeName from Recipe");
    query.exec();
    while(query.next()){
        // Show ingredient on combo box
        ui->cmbRemove->addItem(query.value(0).toString());
        qDebug() << "Filling cmbRemove" << query.value(0).toString();
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}

void RemoveRecipe::on_btnLoad_clicked()
{
    loadComboBox();
}

bool RemoveRecipe::validateUserInput() {
    QString recipeToDelete = ui->cmbRemove->currentText();
    // check if input is void
    if (recipeToDelete.isEmpty()) {
        QMessageBox::warning(this, "Warning", "You are removing all recipes!");
        return true;
    }
    // check if no recipe name match the input
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("select RecipeName from Recipe");
    query.exec();
    while(query.next()) {
        QString existedRecipeName = query.value(0).toString();
        if (recipeToDelete == existedRecipeName) {
            return true;
        }
    }
    QMessageBox::critical(this, "Error", "No recipes'names matched your input!");
    return false;
}

