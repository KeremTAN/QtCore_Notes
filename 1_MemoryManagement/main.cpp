#include <QCoreApplication>
#include <QDebug>
#include "test.h"
#include "source.h"
#include "destination.h"

void wow() {
    std::unique_ptr<Test> t(new Test);
    t->doSomething();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
/*
    qInfo() << "Starting";
    wow();
    qInfo() << "Finished";
*/
    Source s;
    Destination d;

    QObject::connect(&s, &Source::mySignal, &d, &Destination::mySlot);


    s.publisher();
    d.mySlot("Hello Publishers");

    return a.exec();
}
