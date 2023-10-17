#include <QTest>
#include "../recipe.h"
#include "../databaseheader.h"
#include <QModelIndex>
#include <QLineEdit>

class TestRecipe: public QObject
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

    void testloadAllRecipes() {
        Recipe recipe;

        recipe.loadAllRecipes();

        // Verify that the model is not null
        QVERIFY(recipe.model != nullptr);

        // Verify that all ingredient names are listed
        QSqlQueryModel* model = recipe.model;

        // Fetch all ingredient names from the model
        QStringList recipeNames;
        for (int row = 0; row < model->rowCount(); ++row) {
            QModelIndex index = model->index(row, 1); // Assuming the name is in the first column
            recipeNames.append(index.data().toString());
        }

        // Query the database to get all ingredient names
        QSqlDatabase database = QSqlDatabase::database("DB0");
        QSqlQuery query(database);
        query.prepare("SELECT recipeName FROM Recipe");
        QVERIFY(query.exec());

        QStringList databaseRecipeNames;
        while (query.next()) {
            databaseRecipeNames.append(query.value(0).toString());
        }

        // Compare the lists of ingredient names
        QCOMPARE(recipeNames.toList(), databaseRecipeNames.toList());

    }

    void testSearchRecipe() {
        // Simulate user input
        QLineEdit searchline;
        QTest::keyClicks(&searchline, "k");

        // Query the database
        QSqlDatabase database = QSqlDatabase::database("DB0");
        QSqlQuery query(database);
        query.prepare("SELECT RecipeName FROM Recipe WHERE RecipeName LIKE '%" + searchline.text() + "%'");
        QVERIFY(query.exec());

        int matchingRecords = 0;
        // Output actual records retrieved from the database for debugging purposes
        qDebug() << "Actual records retrieved from the database:";
        while (query.next()) {
            QString databaseRecipeName = query.value(0).toString();
            qDebug() << databaseRecipeName;

            // Check if the retrieved ingredient name contains the search text
            if (databaseRecipeName.contains(searchline.text(), Qt::CaseInsensitive)) {
                matchingRecords++;
            }
        }

        // Check if there are any matching records in the database
        QVERIFY(matchingRecords > 0);
    }

};



QTEST_MAIN(TestRecipe)
#include "tst_recipe.moc"

