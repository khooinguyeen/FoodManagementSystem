#include "mealplan.h"
#include "ui_mealplan.h"

MealPlan::MealPlan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MealPlan)
{
    ui->setupUi(this);
}

MealPlan::~MealPlan()
{
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

