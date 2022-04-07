#ifndef TST_TESTDRINKSFACTORY_H
#define TST_TESTDRINKSFACTORY_H

#include <QObject>


class TestDrinksFactory : public QObject
{
    Q_OBJECT

public:
    TestDrinksFactory();
    ~TestDrinksFactory();

private slots:
    void test_make_specialDrinks();

    void test_make_drinks_data();
    void test_make_drinks();




};


#endif // TST_TESTDRINKSFACTORY_H
