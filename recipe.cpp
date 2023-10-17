#include "recipe.h"
#include "ui_recipe.h"

Recipe::Recipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recipe)
{
    ui->setupUi(this);

    loadAllRecipes();
    // initialize pointers
    ptrAddRecipe = new AddRecipe();
    ptrRemoveRecipe = new RemoveRecipe();
}

void Recipe::loadAllRecipes(){
    // Show all available recipes
    QSqlDatabase database = QSqlDatabase::database("DB0");

    if(model == nullptr)
        model = new QSqlQueryModel();

    model->setQuery("select * from Recipe", database);
    ui->tableView->setModel(model);
}

Recipe::~Recipe()
{
    qDebug() << "~Recipe()";
    delete ui;
    delete ptrAddRecipe;
    delete ptrRemoveRecipe;
}

void Recipe::on_btnAdd_clicked()
{
    ptrAddRecipe->setWindowTitle("Add");
    ptrAddRecipe->show();
}


void Recipe::on_btnRemove_clicked()
{
    ptrRemoveRecipe->setWindowTitle("Remove");
    ptrRemoveRecipe->show();
}


void Recipe::on_btnSearch_clicked()
{
    QString recipeName = ui->txtRecipe->text();
    qDebug() << "Recipe Name: " << recipeName;
    QSqlDatabase database = QSqlDatabase::database("DB0");

    if(model == NULL)
        model = new QSqlQueryModel();

    // If the search button is not clicked, show all the available recipes
    if(recipeName.isEmpty()) {
        loadAllRecipes();
    } else {
        model->setQuery("select * from Recipe where RecipeName like '%" + recipeName + "%'", database);
        ui->tableView->setModel(model);
    }
}


void Recipe::on_btnRefresh_clicked()
{
    loadAllRecipes();
}

