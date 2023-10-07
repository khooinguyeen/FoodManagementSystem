#include "mealplan.h"
#include "ui_mealplan.h"

MealPlan::MealPlan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MealPlan)
{
    ui->setupUi(this);
    calendar = ui->calendarWidget;
}

MealPlan::~MealPlan()
{
    qDebug() << "~MealPlan()";
    delete ui;
}

void MealPlan::on_btnLoad_clicked()
{
    QSqlDatabase database = QSqlDatabase::database("DB0");
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


void MealPlan::on_calendarWidget_selectionChanged()
{
    qDebug() << ui->calendarWidget->selectedDate().toString();
}


void MealPlan::on_btnAdd_clicked()
{
    QString date = calendar->selectedDate().toString();
    QString breakfast = ui->cmbBreakfast->currentText();
    QString lunch = ui->cmbLunch->currentText();
    QString dinner = ui->cmbDinner->currentText();
    QString addQuery = "insert into MealPlan (Date, Breakfast, Lunch, Dinner) "
                       "values('" + date + "','" + breakfast + "','" + lunch + "','" + dinner + "')";
    QSqlDatabase database = QSqlDatabase::database("DB0");
    QSqlQuery query(database);


    query.prepare(addQuery);

    qDebug() << "Date: " << date << " Breakfast: " << breakfast << " Lunch: " << lunch << " Dinner: " << dinner;

    query.exec();
    query.finish();
    query.clear();
    qDebug() << "Last query: " << query.lastQuery();
    qDebug() << "Last error: " << query.lastError();
}

