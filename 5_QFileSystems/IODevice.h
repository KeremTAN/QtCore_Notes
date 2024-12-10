#ifndef IODEVICE_H
#define IODEVICE_H
#include <QIODevice>
#include <QBuffer>
#include <QFile>
#include <QDateTime>
#include <QDebug>
class IODeviceExample {
public:
    inline void bufferExample() {
        QBuffer buffer;

        if(buffer.open(QIODevice::ReadWrite)) {
            qInfo() << "Device is open";

            QByteArray data("Hello World");
            for(int i{}; i<5; i++) {
                buffer.write(data);
                buffer.write("\r\n"); // \r = enter
            }

            buffer.seek(0);
            qInfo() << buffer.readAll();

            buffer.close();
        }
        else {
            qInfo() << "Could not open the device";
        }
    }

    inline void fileExample() {
        QString filename = "text.txt";

        QFile file(filename);
        if(file.open(QIODevice::WriteOnly)) { // QIODevice::Append adds to the end of the file
            QString now = QDateTime::currentDateTime().toString();

            QByteArray data{};
            data.append(now.toLocal8Bit());
            data.append(" - ");
            data.append("off");

            file.write(data);
            file.close(); // calls flush
            qInfo() << "Wrote to the file";
        }
        else {
            qInfo() << file.errorString();
        }
    };

    inline void readLines() { // better choice for plain text files
        QString filename = "text.txt";
        QFile file(filename);

        if(!file.isReadable()) return;

        file.seek(0); // go to begining

        while(!file.atEnd()) {
            qInfo() << file.readLine(); // \n
        }
    }

    inline void readChunks() {
        QString filename = "text.txt";
        QFile file(filename);

        if(!file.isReadable()) return;

        file.seek(0); // go to begining

        while(!file.atEnd()) {
            qInfo() << file.read(25); // read 25 byte
        }
    }
};

#endif // IODEVICE_H
