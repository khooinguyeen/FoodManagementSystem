#include <QTest>
#include "../removerecipe.h"
#include "C:\Users\Legion\Documents\GitHub\build-FoodManagementSystem-Desktop_Qt_6_5_2_MinGW_64_bit-Debug\FoodManagementSystem_autogen\include\ui_removerecipe.h"

class TestRemoveRecipe : public QObject
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
        removeRecipe = new RemoveRecipe();
    }

    void cleanup() {
        delete removeRecipe;
    }

    void testLoadButtonBox() {
        // activate combo box
        removeRecipe->on_btnLoad_clicked();
        // verify if combo box is activated
        QVERIFY(removeRecipe->ui->cmbRemove != nullptr);
        // activate and record all ingredients name in combo box
        QStringList recipeNames;
        for (int i = 0; i < removeRecipe->ui->cmbRemove->count(); i++) {
            recipeNames.append(removeRecipe->ui->cmbRemove->itemText(i));
        }

        // Query the database to get all ingredient names
        QSqlDatabase database = QSqlDatabase::database("DB0");
        QSqlQuery query(database);
        query.prepare("select RecipeName from Recipe");
        QVERIFY(query.exec());
        QStringList databaseRecipeNames;
        while (query.next()) {
            databaseRecipeNames.append(query.value(0).toString());
        }
        // check if names matched
        QCOMPARE(recipeNames.toList(), databaseRecipeNames.toList());

    }

    void testRemoveRecipe() {
        // load the combo box
        removeRecipe->on_btnLoad_clicked();
        // Set the combo box selection to the test ingredient and remove click
        removeRecipe->ui->cmbRemove->setCurrentText("potato pie");
        removeRecipe->on_buttonBox_accepted();
        // Verify that the ingredient was successfully removed from the database
        QSqlQuery query(QSqlDatabase::database("DB0"));
        query.prepare("select RecipeName from Recipe where RecipeName = :name");
        query.bindValue(":name", "potato pie");
        QVERIFY(query.exec());
        QVERIFY(!query.next());
    }
private:
    RemoveRecipe *removeRecipe;
};

QTEST_MAIN(TestRemoveRecipe)
#include "tst_removerecipe.moc"
