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
    ~MealPlan();

private slots:
    void on_btnLoad_clicked();

    void on_calendarWidget_selectionChanged();

    void on_btnAdd_clicked();

    void on_btnDelete_clicked();

private:
    Ui::MealPlan *ui;
    QSqlDatabase database;
    QCalendarWidget *calendar;
};

#endif // MEALPLAN_H
