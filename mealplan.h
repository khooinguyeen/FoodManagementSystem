#ifndef MEALPLAN_H
#define MEALPLAN_H

#include <QWidget>
#include "databaseheader.h"
#include <QCalendarWidget>

namespace Ui {
class MealPlan;
}

class MealPlan : public QWidget
{
    Q_OBJECT

public:
    explicit MealPlan(QWidget *parent = nullptr);
    void showMealPlan();
    ~MealPlan();

private slots:
    void on_btnLoad_clicked(); // Load all available recipes

    void on_calendarWidget_selectionChanged(); // Show info of current date when date selection changed

    void on_btnAdd_clicked(); // Add new meal plan to a date

    void on_btnDelete_clicked(); // Delete meal plan of selected date

private:
    // Declare value
    friend class TestMealPlan;
    Ui::MealPlan *ui;
    QSqlDatabase database;
    QCalendarWidget *calendar;
};

#endif // MEALPLAN_H
