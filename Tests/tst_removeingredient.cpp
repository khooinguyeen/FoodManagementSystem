#include <QTest>
#include "../removeingredient.h"
#include "C:\Users\Legion\Documents\GitHub\build-FoodManagementSystem-Desktop_Qt_6_5_2_MinGW_64_bit-Debug\FMS_autogen\include\ui_removeingredient.h"
#include "../databaseheader.h"

class TestRemoveIngredient : public QObject
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
        removeIngredient = new RemoveIngredient();
    }

    void cleanup() {
        delete removeIngredient;
    }

    void testLoadComboxBox() {
        removeIngredient->on_btnLoad_clicked();
        QVERIFY(removeIngredient->ui->cmbRemove != nullptr);
        // activate and record all ingredients name in combo box
        QStringList ingredientNames;
        for (int i = 0; i < removeIngredient->ui->cmbRemove->count(); i++) {
            ingredientNames.append(removeIngredient->ui->cmbRemove->itemText(i));
        }

        // Query the database to get all ingredient names
        QSqlDatabase database = QSqlDatabase::database("DB0");
        QSqlQuery query(database);
        query.prepare("SELECT IngredientName FROM Ingredient");
        QVERIFY(query.exec());
        QStringList databaseIngredientNames;
        while (query.next()) {
            databaseIngredientNames.append(query.value(0).toString());
        }
        // check if names matched
        QCOMPARE(ingredientNames.toList(), databaseIngredientNames.toList());
    }

    void testRemoveIngredient() {
        // load the combo box
        removeIngredient->on_btnLoad_clicked();
        // Set the combo box selection to the test ingredient and remove click
        removeIngredient->ui->cmbRemove->setCurrentText("potato");
        removeIngredient->on_buttonBox_accepted();
        // Verify that the ingredient was successfully removed from the database
        QSqlQuery query(QSqlDatabase::database("DB0"));
        query.prepare("SELECT IngredientName FROM Ingredient WHERE IngredientName = :name");
        query.bindValue(":name", "potato");
        QVERIFY(query.exec());
        QVERIFY(!query.next());
    }


private:
    RemoveIngredient *removeIngredient;
};



QTEST_MAIN(TestRemoveIngredient)
#include "tst_removeingredient.moc"
