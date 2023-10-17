#include <QTest>
#include "../storage.h"
#include "../databaseheader.h"

class TestStorage: public QObject
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


};



QTEST_MAIN(TestStorage)
#include "tst_storage.moc"
