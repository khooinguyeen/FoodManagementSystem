#include "../mealplan.h"
#include "D:\Games and Apps\Qt app\build-FoodManagementSystem-Desktop_Qt_6_6_0_MinGW_64_bit-Debug\FMS_autogen\include\ui_mealplan.h"

#include <QTest>


class TestMealPlan : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase database;
private slots:
    void initTestCase() {
        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "DB0");
        database.setDatabaseName("D:/Games and Apps/Qt app/FoodManagementSystem/FoodManagementSystem.db");
    }
    void testShowMealPlan() {
        MealPlan mealplan;
        mealplan.showMealPlan();
        QDate selectedDate(2023, 10, 11);
        mealplan.ui->calendarWidget->setSelectedDate(selectedDate);

        QTextEdit txtTest;
        txtTest.append("Wed Oct 11 2023");
        txtTest.append("Breakfast: k");
        txtTest.append("Lunch: Spaghetti");
        txtTest.append("Dinner: Spaghetti");

        QCOMPARE(mealplan.ui->txtPlan->toPlainText(), txtTest.toPlainText());
    }
    void cleanUpTestCase() {
        database.close();
        QSqlDatabase::removeDatabase(database.connectionName());
    }
};


QTEST_MAIN(TestMealPlan)
#include "tst_mealplan.moc"
