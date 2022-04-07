#include <QFileInfoList>
#include <QtTest>
#include <iostream>
#include "change.h"
#include "search.h"
// add necessary includes here

class testChange : public QObject
{
    Q_OBJECT

public:
    testChange();
    ~testChange();

private slots:
    void test_case1_data();
    void test_case1();
    void test_case2();
    void test_case2_data();
    void test_case3();
    void test_case3_data();
};

testChange::testChange()
{

}

testChange::~testChange()
{

}


void testChange::test_case1_data()
{
    QTest::addColumn<QString>("inString");
    QTest::addColumn<bool>("isValid");

    QTest::addRow("Test 1") << "#aabbcc" << true;
    QTest::addRow("Test 2") << "#abc" << true;
    QTest::addRow("Test 3") << "#112233" << true;
    QTest::addRow("Test 4") << "#123" << true;
    QTest::addRow("Test 5") << "#aabba" << false;
    QTest::addRow("Test 6") << "Bratwurst" << false;


}

void testChange::test_case1()
{

    QFETCH(QString, inString);
    QFETCH(bool, isValid);


    QFileInfoList fi;
    Change c(fi);
    QVERIFY(c.isValid(inString) == isValid);

}

void testChange::test_case2_data(){

    QTest::addColumn<QString>("start");
    QTest::addColumn<QString>("newC");
    QTest::addColumn<bool>("isValid");

    QTest::addRow("Test 1") << "#aabbcc" << "#ccaabb" << true;
    QTest::addRow("Test 2") << "#123456" << "#aaaaef" << true;
    QTest::addRow("Test 3") << "#AC09c1" << "#9A801F" << true;
    QTest::addRow("Test 4") << "#000" << "#001" << true;
    QTest::addRow("Test 5") << "#000" << "#aaa" << true;
    QTest::addRow("Test 6") << "#fff" << "#ab1702" << true;
    QTest::addRow("Test 7") << "#FFFFFF" << "#AcEa5b" << true;



}

void testChange::test_case2()
{
    QFETCH(QString, start);
    QFETCH(QString, newC);
    QFETCH(bool, isValid);

    QString str = start;
    QFileInfoList fi;
    Change c(fi);
    QRegExp a(start);

    str = c.colorChange(start, newC);

    //QVERIFY((a.exactMatch(start)) == isValid);
    QVERIFY((a.exactMatch(newC)) == !isValid);

}

void testChange::test_case3()
{

    QFETCH(QString, hexCode);
    QFETCH(QString, hex);
    QFETCH(bool, b);

    QString inf;
    Suche a(inf);


    QVERIFY((a.hexErkennung(hexCode) == hex) == b);

}

void testChange::test_case3_data()
{
    QTest::addColumn<QString>("hexCode");
    QTest::addColumn<QString>("hex");
    QTest::addColumn<bool>("b");

    QTest::addRow("Test 1") << "#123456" << "#123456" << true;
    QTest::addRow("Test 2") << "#18abe3" << "#18abe3" << true;
    QTest::addRow("Test 3") << "#80e;/1" << "#80e" << true;
    QTest::addRow("Test 4") << "#ab4;co" << "#ab4" << true;
    QTest::addRow("Test 5") << "#123\"am" << "#123" << true;

}
QTEST_APPLESS_MAIN(testChange)

#include "tst_testchange.moc"
