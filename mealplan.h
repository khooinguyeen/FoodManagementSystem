#ifndef MEALPLAN_H
#define MEALPLAN_H

#include <QWidget>
#include "databaseheader.h"
#include "validation.h"
#include <QCalendarWidget>

namespace Ui {
class MealPlan;
}

class MealPlan : public QWidget, public Validation
{
    Q_OBJECT

public:
    explicit MealPlan(QWidget *parent = nullptr);

    // check user input validity
    bool validateUserInput();
    // Show mealplan information
    void showMealPlan();

    ~MealPlan();

private slots:
    void on_btnLoad_clicked(); // Load all available recipes

    void on_calendarWidget_selectionChanged(); // Show info of current date when date selection changed

    void on_btnAdd_clicked(); // Add new meal plan to a date

    void on_btnDelete_clicked(); // Delete meal plan of selected date

private:
    // Declare value
    Ui::MealPlan *ui;
    QSqlDatabase database;
    QCalendarWidget *calendar;
};

#endif // MEALPLAN_H
