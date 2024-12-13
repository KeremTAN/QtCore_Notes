#include <QCoreApplication>
#include "IODevice.h"
#include "TextStream.h"
#include "DataStream.h"
#include "DirExample.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

   // IODeviceExample examples{};
    //examples.fileExample();

   // TextStream{}.run();
   //DataStream{}.run();

   DirExample{}.run();

    return a.exec();
}
