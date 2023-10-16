#include <QTest>

class TestIngredient: public QObject
{
    Q_OBJECT
private slots:
    void toUpper();
};

void TestIngredient::toUpper()
{
    QString str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
}

QTEST_MAIN(TestIngredient)
#include "tst_ingredient.moc"
