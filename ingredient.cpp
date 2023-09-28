#include "ingredient.h"
#include "ui_ingredient.h"

Ingredient::Ingredient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ingredient)
{
    ui->setupUi(this);

    loadAllIngredients();

    ptrAddIngredient = new AddIngredient();
    ptrRemoveIngredient = new RemoveIngredient();
}

void Ingredient::loadAllIngredients() {
    QSqlDatabase database = QSqlDatabase::database("DB0");

    if (model == nullptr)
        model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM Ingredient", database);
    ui->tableView->setModel(model);
}

Ingredient::~Ingredient()
{
    qDebug() << "~Ingredient";
    delete ui;
    delete ptrAddIngredient;
    delete ptrRemoveIngredient;
}

void Ingredient::on_btnAdd_clicked()
{
    ptrAddIngredient->show();
}

void Ingredient::on_btnRemove_clicked()
{
    ptrRemoveIngredient->show();
}

void Ingredient::on_btnSearch_clicked()
{
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





