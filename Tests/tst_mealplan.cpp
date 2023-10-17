#include "../mealplan.h"
//#include "D:\Games and Apps\Qt app\build-FoodManagementSystem-Desktop_Qt_6_6_0_MinGW_64_bit-Debug\FMS_autogen\include\ui_mealplan.h"
#include "C:\Users\Legion\Documents\GitHub\build-FoodManagementSystem-Desktop_Qt_6_5_2_MinGW_64_bit-Debug\FoodManagementSystem_autogen\include\ui_mealplan.h"

#include <QTest>


class TestMealPlan : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase database;
private slots:
    void initTestCase() {
        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "DB0");
//        database.setDatabaseName("D:/Games and Apps/Qt app/FoodManagementSystem/FoodManagementSystem.db");
    database.setDatabaseName("C:/Users/Legion/Documents/GitHub/FoodManagementSystem/FoodManagementSystem.db");

    }
    void testShowMealPlan() {
        MealPlan mealplan;
        QVERIFY(mealplan.ui->txtPlan->toPlainText() != "");
    }
    void cleanUpTestCase() {
        database.close();
        QSqlDatabase::removeDatabase(database.connectionName());
    }
};


QTEST_MAIN(TestMealPlan)
#include "tst_mealplan.moc"
