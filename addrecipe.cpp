#include "addrecipe.h"
#include "ui_addrecipe.h"
#include <QMessageBox>

AddRecipe::AddRecipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecipe)
{
    ui->setupUi(this);
}

AddRecipe::~AddRecipe()
{
    qDebug() << "~AddRecipe()";
    delete ui;
}

void AddRecipe::on_btnSave_clicked()
{
    if (validateUserInput() == false) {
        return;
    }
    // Assign the QStrings with the value input from the line edit
    QString recipeName = ui->recipeNameLineEdit->text();
    QString ingredients = ui->ingredientsLineEdit->text();
    QString cookingTime = ui->cookingTimeLineEdit->text();
    QString nutrition = ui->nutritionLineEdit->text();
    QString instruction = ui->txtInstruction->toPlainText();

    // Add new recipe to database
    QString addQuery = "insert into Recipe (RecipeName, Ingredients, CookingTime, Nutrition, Instruction) "
        "values('" + recipeName + "','" + ingredients + "','" + cookingTime + "','" + nutrition + "','" + instruction + "')";
    qDebug() << "Recipe Name: " << recipeName
             << " Ingredients: " << ingredients
             << " Cooking Time: " << cookingTime
             << " Nutrition: " << nutrition
             << " Instruction: " << instruction;
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare(addQuery);
    query.exec();
    query.finish();
    query.clear();
    QMessageBox::information(this, "Success", "Added succesfully!");
    qDebug() << "Last error: " << query.lastError().text();
    on_btnReset_clicked(); // Clear all the inputs from line edit after finished adding new recipes
}


void AddRecipe::on_btnReset_clicked()
{
    // Clear all the line edit
    ui->recipeNameLineEdit->clear();
    ui->ingredientsLineEdit->clear();
    ui->cookingTimeLineEdit->clear();
    ui->nutritionLineEdit->clear();
    ui->txtInstruction->clear();
}

bool AddRecipe::validateUserInput() {
    QString recipeName = ui->recipeNameLineEdit->text();
    // check if ingredient name is void
    if (recipeName.isEmpty()) {
        QMessageBox::critical(this, "Validation Error", "Input cannot be empty.");
        return false;
    }
    // check if ingredient name already exists
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);
    query.prepare("select RecipeName from Recipe");
    query.exec();
    while(query.next()) {
        QString existedRecipeName = query.value(0).toString();
        if (recipeName == existedRecipeName) {
            QMessageBox::critical(this,"Validation Error", "Name already exist!");
            query.finish();
            query.clear();
            qDebug() << "Last error: " << query.lastError().text();
            return false;
        }
    }
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    return true;
}

