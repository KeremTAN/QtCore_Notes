#include <QCoreApplication>
#include "test.h"
#include "watcher.h"
#include <QVariant>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test tester;
    Watcher watcher;

    QObject::connect(&tester, &Test::messageChanged, &watcher, &Watcher::messageChanged);
    tester.setMessage("Test Connected...");

    tester.setProperty("message", QVariant("Property works and don't need Qt::connect"));

    return a.exec();
}
