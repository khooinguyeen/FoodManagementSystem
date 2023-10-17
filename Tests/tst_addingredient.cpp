#include <QTest>
#include "../addingredient.h"
#include "C:\Users\Legion\Documents\GitHub\build-FoodManagementSystem-Desktop_Qt_6_5_2_MinGW_64_bit-Debug\FMS_autogen\include\ui_addingredient.h"
#include "../databaseheader.h"

class TestAddIngredient : public QObject
{
    Q_OBJECT
public:
    QSqlDatabase database;

private slots:
    void initTestCase() {
        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "DB0");
        database.setDatabaseName("C:/Users/Legion/Documents/GitHub/FoodManagementSystem/FoodManagementSystem.db");
        QVERIFY(database.open());
    }
    void cleanupTestCase() {
        database.close();
        QSqlDatabase::removeDatabase(database.connectionName());
    }

    void init() {
        addIngredient = new AddIngredient();
    }

    void cleanup() {
        delete addIngredient;
    }

    void testAddIngredient() {
        // test input
        QString ingredientName = "potato";
        QString ingredientDescription = "king potato";

        // add input to correspond line edits
        addIngredient->ui->ingredientNameLineEdit->setText(ingredientName);
        addIngredient->ui->txtDescription->setText(ingredientDescription);

        // add button trigger
        addIngredient->on_btnSave_clicked();

        // verify in database
        QSqlQuery query(QSqlDatabase::database("DB0"));
        query.prepare("select IngredientName from Ingredient where IngredientName = :name");
        query.bindValue(":name", ingredientName);
        QVERIFY(query.exec());
        QVERIFY(query.next());
    }

private:
    AddIngredient *addIngredient;
};



QTEST_MAIN(TestAddIngredient)
#include "tst_addingredient.moc"
