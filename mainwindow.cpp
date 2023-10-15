#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // initialize database
    database = QSqlDatabase::addDatabase("QSQLITE", "DB0");
//    database.setDatabaseName("C:/Users/Legion/Documents/GitHub/FoodManagementSystem/FoodManagementSystem.db");
    database.setDatabaseName("D:/Games and Apps/Qt app/FoodManagementSystem/FoodManagementSystem.db");
    if(!database.open()){
        qDebug() << "Error: Unable to open database..";
    }
    else{
        qDebug() << "Database open successfully..";
    }

    // Initialize pointer to all other features
    ptrIngredient = new Ingredient();
    ptrRecipe = new Recipe();
    ptrMealPlan = new MealPlan();
    ptrStorage = new Storage();
    ptrOnlineShopping = new OnlineShopping();
    ptrMarketPurchasing = new MarketPurchasing();

}

MainWindow::~MainWindow()
{
    // Delete pointers to prevent segmentation fault

    delete ui;
    delete ptrIngredient;
    delete ptrRecipe;
    delete ptrMealPlan;
    delete ptrStorage;

    delete ptrOnlineShopping;
    delete ptrMarketPurchasing;

    database.close();
    QSqlDatabase::removeDatabase(database.connectionName());
}

// Show window of the feature associated with the clicked button
void MainWindow::on_ingredientButton_clicked()
{
    ptrIngredient->show();
}


void MainWindow::on_recipeButton_clicked()
{
    ptrRecipe->show();
}


void MainWindow::on_pushButton_clicked()
{
    ptrMealPlan->show();
}



void MainWindow::on_storageButton_clicked()
{
    ptrStorage->show();
}

// Display both window of OnlineShopping and MarketPurchasing when the shopping list button is clicked
void MainWindow::on_shoppinglistButton_clicked()
{
    ptrOnlineShopping->show();
    ptrMarketPurchasing->show();
}

