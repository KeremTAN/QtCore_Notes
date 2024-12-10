#include <QCoreApplication>
#include "IODevice.h"
#include "TextStream.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    IODeviceExample examples{};
    //examples.fileExample();

    TextStream{}.run();

    return a.exec();
}
