#include "addrecipe.h"
#include "ui_addrecipe.h"

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
    QString recipeName = ui->recipeNameLineEdit->text();
    QString ingredients = ui->ingredientsLineEdit->text();
    QString cookingTime = ui->cookingTimeLineEdit->text();
    QString nutrition = ui->nutritionLineEdit->text();
    QString instruction = ui->txtInstruction->toPlainText();
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
    qDebug() << "Last error: " << query.lastError().text();
    on_btnReset_clicked();
}


void AddRecipe::on_btnReset_clicked()
{
    ui->recipeNameLineEdit->clear();
    ui->ingredientsLineEdit->clear();
    ui->cookingTimeLineEdit->clear();
    ui->nutritionLineEdit->clear();
    ui->txtInstruction->clear();
}

