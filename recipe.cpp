#include "recipe.h"
#include "ui_recipe.h"

Recipe::Recipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recipe)
{
    ui->setupUi(this);

    loadAllRecipes();

    ptrAddRecipe = new AddRecipe();
    ptrRemoveRecipe = new RemoveRecipe();
}

void Recipe::loadAllRecipes(){
    QSqlDatabase database = QSqlDatabase::database("DB0");

    if(model == nullptr)
        model = new QSqlQueryModel();

    model->setQuery("select * from Recipe", database);
    ui->tableView->setModel(model);
}

Recipe::~Recipe()
{
    delete ui;
    delete ptrAddRecipe;
    delete ptrRemoveRecipe;
}

void Recipe::on_btnAdd_clicked()
{
    ptrAddRecipe->show();
}


void Recipe::on_btnRemove_clicked()
{
    ptrRemoveRecipe->show();
}


void Recipe::on_btnSearch_clicked()
{
    QString recipeName = ui->txtRecipe->text();
    qDebug() << "Recipe Name: " << recipeName;
    QSqlDatabase database = QSqlDatabase::database("DB0");

    if(model == NULL)
        model = new QSqlQueryModel();

    if(recipeName.isEmpty()) {
        loadAllRecipes();
    } else {
        model->setQuery("select * from Recipe where RecipeName like '%" + recipeName + "%'", database);
        ui->tableView->setModel(model);
    }
}

