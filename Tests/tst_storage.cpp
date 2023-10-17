#include <QTest>
#include "../storage.h"
#include "../list.h"
#include "D:\Games and Apps\Qt app\build-FoodManagementSystem-Desktop_Qt_6_6_0_MinGW_64_bit-Debug\FoodManagementSystem_autogen\include\ui_list.h"


class TestStorage : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase database;
    Storage *storage;
private slots:
    void initTestCase()
    {
        database = QSqlDatabase::addDatabase("QSQLITE", "DB0");
        database.setDatabaseName("D:/Games and Apps/Qt app/FoodManagementSystem/FoodManagementSystem.db");
    }

    void cleanupTestCase() {
        database.close();
        QSqlDatabase::removeDatabase(database.connectionName());
    }

    void init() {
        storage = new Storage();
    }

    void cleanup() {
        delete storage;
    }
    void testListWidget() {
        storage->on_btnLoad_clicked();
        // Get the expected ingredient names from the test database.
        QStringList expectedIngredientNames;
        for (int i = 0; i < storage->ui->listWidget->count(); i++) {
            QListWidgetItem* item = storage->ui->listWidget->item(i);
            expectedIngredientNames.append(item->text());
        }

        QStringList actualIngredientNames;
        QSqlQuery query(database);
        query.prepare("select IngredientName from Storage");
        QVERIFY(query.exec());
        while(query.next()) {
            QString currentIngredientName = query.value(0).toString();
            actualIngredientNames.append(currentIngredientName);
        }



        // Compare the expected and actual ingredient names.
        QCOMPARE(actualIngredientNames.toList(), expectedIngredientNames.toList());
    }

//    void testShowInfo()
//    {
//        Storage storage;
//        storage.on_btnLoad_clicked();
//        qDebug() << "dit me";
//        QListWidgetItem* firstItem = storage.ui->listWidget->item(0);
//        //qDebug() << "dit me";
//        //storage.ui->listWidget->setCurrentItem(firstItem);
//        qDebug() << "dit me";
//        storage.on_listWidget_itemClicked(firstItem);
//        qDebug() << "dit me";

//        QTextEdit txtTest;
//        txtTest.append("INGREDIENT INFORMATION");
//        txtTest.append("\n");
//        txtTest.append("ID: 2");
//        txtTest.append("Ingredient name: ngu");
//        txtTest.append("Quantity: 0");
//        txtTest.append("Expired date: ngu");


//        QCOMPARE(storage.ui->txtInfo->toPlainText(), txtTest.toPlainText());
//    }


};

QTEST_MAIN(TestStorage)
#include "tst_storage.moc"
