#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QGuiApplication>
#include <QScreen>

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
    ptrIngredient->setWindowTitle("Ingredient Window");
    ptrIngredient->show();
}


void MainWindow::on_recipeButton_clicked()
{
    ptrRecipe->setWindowTitle("Recipe Window");
    ptrRecipe->show();
}


void MainWindow::on_mealplanButton_clicked()
{
    ptrMealPlan->setWindowTitle("Meal PLan Window");
    ptrMealPlan->show();
}



void MainWindow::on_storageButton_clicked()
{
    ptrStorage->setWindowTitle("Storage Window");
    ptrStorage->show();
}

// Display both window of OnlineShopping and MarketPurchasing when the shopping list button is clicked
void MainWindow::on_shoppinglistButton_clicked()
{
    // Get the primary screen's geometry
    QScreen* primaryScreen = QGuiApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();

    // Calculate the width, height, and positioning for both windows
    int windowWidth = 539; // Adjust to your window width
    int windowHeight = 313; // Adjust to your window height
    int gap = 10; // Adjust the gap as needed

    // Calculate the position for the first window (centered)
    int x1 = (screenGeometry.width() - (windowWidth * 2 + gap)) / 2;
    int y1 = (screenGeometry.height() - windowHeight) / 2;

    // Calculate the position for the second window (next to the first window)
    int x2 = x1 + windowWidth + gap;

    // Set the geometry for the first window
    ptrOnlineShopping->setGeometry(x1, y1, windowWidth, windowHeight);

    // Set the geometry for the second window
    ptrMarketPurchasing->setGeometry(x2, y1, windowWidth, windowHeight);

    ptrOnlineShopping->setWindowTitle("Online Shopping Window");
    ptrMarketPurchasing->setWindowTitle("Market Purchasing Window");

    ptrOnlineShopping->show();
    ptrMarketPurchasing->show();
}

