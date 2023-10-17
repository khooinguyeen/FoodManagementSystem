#include <QTest>
#include "../ingredient.h"
#include "C:\Users\Legion\Documents\GitHub\build-FoodManagementSystem-Desktop_Qt_6_5_2_MinGW_64_bit-Debug\FoodManagementSystem_autogen\include\ui_ingredient.h"

class TestIngredient : public QObject
{
    Q_OBJECT
public:
    QSqlDatabase database;

private slots:
    void initTestCase() {
        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "DB0");
        database.setDatabaseName("C:/Users/Legion/Documents/GitHub/FoodManagementSystem/FoodManagementSystem.db");
    }
    void cleanupTestCase() {
        database.close();
        QSqlDatabase::removeDatabase(database.connectionName());
    }

    void testloadAllIngredients() {
        Ingredient ingredient;
        ingredient.loadAllIngredients();

        // Verify that the model is not null
        QVERIFY(ingredient.model != nullptr);

        // Verify that all ingredient names are listed
        QSqlQueryModel* model = ingredient.model;

        // Fetch all ingredient names from the model
        QStringList ingredientNames;
        for (int row = 0; row < model->rowCount(); ++row) {
            QModelIndex index = model->index(row, 1); // Assuming the name is in the first column
            ingredientNames.append(index.data().toString());
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

        // Compare the lists of ingredient names
        QCOMPARE(ingredientNames.toList(), databaseIngredientNames.toList());

    }
    void testSearchIngredient() {

        Ingredient ingredient;
        const QString expectedIngredientName = "ga";
        ingredient.ui->txtIngredient->setText(expectedIngredientName);

        // Perform the function
        ingredient.on_btnSearch_clicked();

        // Verify that the model is updated correctly, possibly by checking if it contains the expected ingredient.
        QSqlQueryModel* model = ingredient.model;
        QVERIFY(model != nullptr);

        bool nameMatched = false;

        for (int row = 0; row < model->rowCount(); ++row) {
            QModelIndex index = model->index(row, 1); // Assuming the name is in the first column
            QString actualIngredientName = index.data().toString();

            if (actualIngredientName == expectedIngredientName) {
                nameMatched = true;
                break;
            }
        }
        QVERIFY(nameMatched);
    }
};



QTEST_MAIN(TestIngredient)
#include "tst_ingredient.moc"
