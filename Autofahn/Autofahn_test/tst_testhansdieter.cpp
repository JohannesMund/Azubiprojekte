#include <QtTest>
#include <cdrinkfactory.h>
#include "chansdieter.h"
#include "tst_testhansdieter.h"
// add necessary includes here



TestHansDieter::TestHansDieter()
{}

TestHansDieter::~TestHansDieter()
{}



void TestHansDieter::test_hans_dieter()
{
    CHansDieter d;

    QCOMPARE(d.getName(), "Hans-Dieter");
    QCOMPARE(d.IsFahrtauglich(), true);

    auto drink = CDrinkFactory::makeDrink(CDrink::eSchnaps, "Schnaps");
    d.drink(drink);
    d.drink(drink);

    QCOMPARE(d.IsFahrtauglich(), true);

}
