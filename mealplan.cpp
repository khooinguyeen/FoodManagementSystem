#include "mealplan.h"
#include "ui_mealplan.h"
#include <QMessageBox>

// Initialize ui, mealplan and calendar
MealPlan::MealPlan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MealPlan)
{
    ui->setupUi(this);
    calendar = ui->calendarWidget;
    database = QSqlDatabase::database("DB0");
    showMealPlan();
}

MealPlan::~MealPlan()
{
    qDebug() << "~MealPlan()";
    delete ui;
}

void MealPlan::on_btnLoad_clicked()
{
    ui->cmbBreakfast->clear();
    ui->cmbLunch->clear();
    ui->cmbDinner->clear();
    QSqlQuery query(database);

    query.prepare("select RecipeName from Recipe");
    query.exec();
    while(query.next()) {
        ui->cmbBreakfast->addItem(query.value(0).toString());
        ui->cmbLunch->addItem(query.value(0).toString());
        ui->cmbDinner->addItem(query.value(0).toString());
        qDebug() << "Filling ComboBox" << query.value(0).toString();
    }

    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}

// Show meal plan of selected date
void MealPlan::on_calendarWidget_selectionChanged()
{
    showMealPlan();
}


void MealPlan::on_btnAdd_clicked()
{
    // Convert the inputs
    QString date = calendar->selectedDate().toString();
    QString breakfast = ui->cmbBreakfast->currentText();
    QString lunch = ui->cmbLunch->currentText();
    QString dinner = ui->cmbDinner->currentText();
    QString addQuery = "insert into MealPlan (Date, Breakfast, Lunch, Dinner) "
                       "values('" + date + "','" + breakfast + "','" + lunch + "','" + dinner + "')";
    QSqlQuery query(database);


    query.prepare(addQuery);

    qDebug() << "Date: " << date << " Breakfast: " << breakfast << " Lunch: " << lunch << " Dinner: " << dinner;

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Changes has been done!");
    }
    else {
        QMessageBox::critical(this, "Error", "Errors when making changes!");
    }
    query.finish();
    query.clear();
    qDebug() << "Last query: " << query.lastQuery();
    qDebug() << "Last error: " << query.lastError();
    showMealPlan();
}


void MealPlan::on_btnDelete_clicked()
{
    // Delete the plan of the selected date
    QString planToDelete = calendar->selectedDate().toString();
    QString deleteQuery = "delete from MealPlan where Date like '%" + planToDelete + "%'";
    QSqlQuery query(database);
    query.prepare(deleteQuery);
    if (query.exec()) {
        QMessageBox::information(this, "Success", "Deleted successfully!");
    }
    else {
        QMessageBox::information(this, "Error", "Error when deleting!");
    }
    query.finish();
    query.clear();
    qDebug() << "Last error: " << query.lastError().text();
    showMealPlan();
}


void MealPlan::showMealPlan()
{
    ui->txtPlan->clear();
    qDebug() << ui->calendarWidget->selectedDate().toString("yyyy-MM-dd");
    QString selectedDate = calendar->selectedDate().toString();
    ui->txtPlan->append(calendar->selectedDate().toString());
    QSqlQuery query(database);
    query.prepare("select Breakfast, Lunch, Dinner from MealPlan where Date like '%" + selectedDate + "%'");
    query.exec();
    // Assign QString values with values found from query and print it to line edit
    if (query.next()) {
        QString breakfast = query.value(0).toString();
        QString lunch = query.value(1).toString();
        QString dinner = query.value(2).toString();
        ui->txtPlan->append("Breakfast: " + breakfast);
        ui->txtPlan->append("Lunch: " + lunch);
        ui->txtPlan->append("Dinner: " + dinner);
    }
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
}
