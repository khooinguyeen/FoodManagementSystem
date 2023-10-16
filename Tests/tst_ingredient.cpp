#include <QTest>
#include "../ingredient.h"
#include "../databaseheader.h"
#include <QModelIndex>

class TestIngredient: public QObject
{
    Q_OBJECT
public:
    QSqlDatabase database;
private slots:
    void inItTestCase() {
        QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE", "DB0");
        database.setDatabaseName("C:/Users/Legion/Documents/GitHub/FoodManagementSystem/FoodManagementSystem.db");
    }
    void cleanUpTestCase() {
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
};



QTEST_MAIN(TestIngredient)
#include "tst_ingredient.moc"
