#include <QtTest>
#include <chansdieter.h>
#include "cdrinkfactory.h"
#include "tst_testdrinksfactory.h"
// add necessary includes here


Q_DECLARE_METATYPE(CDrink::ESorte)


TestDrinksFactory::TestDrinksFactory()
{

}

TestDrinksFactory::~TestDrinksFactory()
{

}


void TestDrinksFactory::test_make_drinks_data()
{
    QTest::addColumn<CDrink::ESorte>("sorte");
    QTest::addColumn<QString>("name");
    QTest::addColumn<double>("alkohol");

    QTest::addRow("Flens Bier") << CDrink::eBier << "Flens" << 0.1;
    QTest::addRow("Rockstar Energy") << CDrink::eEnergy<< "Rockstar" << -0.01;
    QTest::addRow("Whiskey") << CDrink::eSchnaps<< "Ardbeg" << 0.3;  
    QTest::addRow("Gerolsteiner Sprudel") << CDrink::eMineralwasser << "Gerolsteiner Sprudel" << 0.0;

    QTest::addRow("???") << CDrink::eUnbekannt<< "Hexensuppe" << 1.0;

}

void TestDrinksFactory::test_make_drinks()
{
    QFETCH(CDrink::ESorte, sorte);
    QFETCH(QString, name);
    QFETCH(double, alkohol);

    CDrink* drink = CDrinkFactory::makeDrink(sorte, name.toStdString());

    QVERIFY(drink != nullptr);
    QCOMPARE(QString::fromStdString(drink->getName()),name);
    QVERIFY(drink->getSorte() == sorte);
    QCOMPARE(drink->getAlkoholPegel(), alkohol);

}


void TestDrinksFactory::test_make_specialDrinks()
{

    auto drink = CDrinkFactory::makeRedBull();
    QCOMPARE(QString::fromStdString(drink->getName()), QString("RedBull"));
    QCOMPARE(drink->getSorte(), CDrink::eEnergy);
    QCOMPARE(drink->getAlkoholPegel(), -0.01);

    auto drink2 = CDrinkFactory::makeBecks();
    QCOMPARE(QString::fromStdString(drink2->getName()), QString("Beck's Pils"));
    QCOMPARE(drink2->getSorte(), CDrink::eBier);
    QCOMPARE(drink2->getAlkoholPegel(), 0.1);

}



