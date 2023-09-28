#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    database = QSqlDatabase::addDatabase("QSQLITE", "DB0");
    database.setDatabaseName("D:/Games and Apps/Qt app/FoodManagementSystem/FoodManagementSystem.db");

    if(!database.open()){
        qDebug() << "Error: Unable to open database..";
    }
    else{
        qDebug() << "Database open successfully..";
    }


    ptrIngredient = new Ingredient();
    ptrRecipe = new Recipe();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrIngredient;
    delete ptrRecipe;

    database.close();
    QSqlDatabase::removeDatabase(database.connectionName());
}

void MainWindow::on_ingredientButton_clicked()
{
    ptrIngredient->show();
}


void MainWindow::on_recipeButton_clicked()
{
    ptrRecipe->show();
}

