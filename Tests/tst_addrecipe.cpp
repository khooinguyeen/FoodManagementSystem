#include <QTest>
#include "../addrecipe.h"
#include "C:\Users\Legion\Documents\GitHub\build-FoodManagementSystem-Desktop_Qt_6_5_2_MinGW_64_bit-Debug\FoodManagementSystem_autogen\include\ui_addrecipe.h"
#include "../databaseheader.h"

class TestAddRecipe : public QObject
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
        addRecipe = new AddRecipe();
    }

    void cleanup() {
        delete addRecipe;
    }

    void testAddIngredient() {
        // test input
        QString recipeName = "potato pie";
        QString recipeIngredients = "potato, flour, egg";
        QString cookingTime = "1 hour";
        QString nutrition = "fat";
        QString instruction = "nothing";
        // set text in corresponding lines
        addRecipe->ui->recipeNameLineEdit->setText(recipeName);
        addRecipe->ui->ingredientsLineEdit->setText(recipeIngredients);
        addRecipe->ui->cookingTimeLineEdit->setText(cookingTime);
        addRecipe->ui->nutritionLineEdit->setText(nutrition);
        addRecipe->ui->txtInstruction->setText(instruction);
        // save into database
        addRecipe->on_btnSave_clicked();
        // verify in database
        QSqlQuery query(QSqlDatabase::database("DB0"));
        query.prepare("select RecipeName from Recipe where RecipeName = :name");
        query.bindValue(":name", recipeName);
        QVERIFY(query.exec());
        QVERIFY(query.next());
    }

private:
    AddRecipe* addRecipe;
};



QTEST_MAIN(TestAddRecipe)
#include "tst_addrecipe.moc"
