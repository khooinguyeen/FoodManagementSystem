#ifndef MEALPLAN_H
#define MEALPLAN_H

#include <QWidget>
#include "databaseheader.h"

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

private:
    Ui::MealPlan *ui;
    QSqlDatabase database;
};

#endif // MEALPLAN_H
