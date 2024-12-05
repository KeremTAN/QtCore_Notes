#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QSocketNotifier>
#include <iostream>
#include "radio.h"
#include "station.h"


void turnOnOff(bool&& isConnected, const Station* (&channels)[3], Radio* myRadio) {
    qInfo() << "Turning the radio " << (isConnected ? "on" : "off");

    for(const Station*& channel : channels) {
        isConnected ?
            myRadio->connect(channel, &Station::send, myRadio, &Radio::listen) :
            myRadio->disconnect(channel, &Station::send, myRadio, &Radio::listen);
    }

    qInfo() << "Radio " << (isConnected ? "on" : "off") << Qt::endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Radio myRadio{};
    const Station* channels[3];


    channels[0] = new const Station(&myRadio, 57, "SinopFM");
    channels[1] = new const Station(&myRadio, 16, "BursaFM");
    channels[2] = new const Station(&myRadio, 26, "EsesFM");

    myRadio.connect(&myRadio, &Radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection);


    turnOnOff(true,channels, &myRadio);

    while(true) {

        QTextStream qout(stdout);
        qout << "Enter on, off, test or quit: " << Qt::endl;
        qout.flush();

        QTextStream qtin(stdin);
        QString line = qtin.readLine().trimmed().toUpper();

        if(line == "ON") {
            turnOnOff(true, channels, &myRadio);
        }

        else if(line == "OFF") {
            turnOnOff(false, channels, &myRadio);
        }

        else if(line == "TEST") {
            for(const Station*& channel : channels) {
                channel->broadcast("Broadcasting live!");
            }
        }
        else if(line == "QUIT") {
            qInfo() << "Quiting...";
            emit myRadio.quit();
        }

    };


    return a.exec();
}
