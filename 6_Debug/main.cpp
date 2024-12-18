#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>
#include "logger.h"
#include "test.h"

Q_DECLARE_LOGGING_CATEGORY(network);
Q_LOGGING_CATEGORY(network, "network");


void mainCategory() {
    // part1
    qInfo() << "test";

    qInfo(network) << "test";
    qWarning(network) << "test";

    //turn it off
    QLoggingCategory::setFilterRules("network.debug=false");

    qDebug(network) << "It will not printed";

    if(!network().isDebugEnabled()) {
        QLoggingCategory::setFilterRules("network.debug=true");
        qDebug(network) << "Network is enabled";
    }

    qDebug(network) << "yes";
    // ----------------------------------------------------------

    // part2 More Simple
    QLoggingCategory logTest("testing");
    logTest.setEnabled(QtMsgType::QtDebugMsg, false);

    qDebug() << "Debug = " << logTest.isDebugEnabled();
    qInfo() << "Info = " << logTest.isInfoEnabled();

    qDebug(logTest) << "This is a debug";
    qInfo(logTest) << "This is a info";
}

int main(int argc, char*argv[]) {
    QCoreApplication a(argc, argv);

    // qInfo() << "File:" << Logger::filename;
    // Logger::attach();

    // qInfo() << "test";

    // Logger::logging = false;
    // qInfo() << "This will not be logged";
    // Logger::logging = true;

    // Test t;
    // t.testing();

    // qInfo() << "Finished";

    mainCategory();

    return a.exec();
}
