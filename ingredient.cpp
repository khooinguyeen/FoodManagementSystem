#include "ingredient.h"
#include "ui_ingredient.h"

Ingredient::Ingredient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ingredient)
{
    ui->setupUi(this);

    loadAllIngredients(); // Display all the available ingredients in database

    // Initialize pointers
    ptrAddIngredient = new AddIngredient();
    ptrRemoveIngredient = new RemoveIngredient();
}

void Ingredient::loadAllIngredients() {
    // Show all ingredients
    QSqlDatabase database = QSqlDatabase::database("DB0");

    if (model == nullptr)
        model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM Ingredient", database);
    ui->tableView->setModel(model); // Show the database table in the table view
}

Ingredient::~Ingredient()
{
    // Delete all ptr to prevent seg fault
    qDebug() << "~Ingredient";
    delete ui;
    delete ptrAddIngredient;
    delete ptrRemoveIngredient;
}

void Ingredient::on_btnAdd_clicked()
{
    ptrAddIngredient->show(); // Show AddIngredient window
}

void Ingredient::on_btnRemove_clicked()
{
    ptrRemoveIngredient->show(); // Show RemoveIngredient window
}

void Ingredient::on_btnSearch_clicked()
{
    // Search for ingredient
    QString ingredientName = ui->txtIngredient->text();
    qDebug() << "Ingredient Name: " << ingredientName;
    QSqlDatabase database = QSqlDatabase::database("DB0");

    if(model == NULL)
        model = new QSqlQueryModel();

    if(ingredientName.isEmpty()) {
        loadAllIngredients();
    }
    else {
        model->setQuery("select * from Ingredient where IngredientName like '%" + ingredientName + "%'", database);
        ui->tableView->setModel(model);
    }
}





