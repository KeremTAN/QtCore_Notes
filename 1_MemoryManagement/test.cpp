#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    qInfo() << this <<"Ctor\n";
}

Test::~Test()
{
    qInfo() << this << "Dtor\n";
}

void Test::doSomething() {
    qInfo() << this << Q_FUNC_INFO;
};
