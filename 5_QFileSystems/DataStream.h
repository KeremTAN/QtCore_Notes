#ifndef DATASTREAM_H
#define DATASTREAM_H

#include <QFile>
#include <QDebug>

class DataStream {

    inline bool write(QFile& file) {
        if(!file.open(QIODevice::WriteOnly)) {
            qInfo() << "Unable to write to file!";
            return false;
        }

        QDataStream stream(&file);
        stream.setVersion(QDataStream::Qt_6_7); // define stream version becaue every qt version has different serilizaiton tip. When define version, Qt knows how serializate the data

        uint8_t age{ 55 };
        QString name{ "Kerem " };
        float weight { 110.6 };

        stream << age << name << weight;
        if(!file.flush()) {
            qInfo() << file.errorString();
            file.close();
            return false;
        }

        qInfo() << "File written";
        file.close(); // close includes flush
        return true;
    }

    inline bool read(QFile& file) {

        if(!file.open(QIODevice::ReadOnly)) {
            qInfo() << "Unable to read to file!";
            return false;
        }

        QDataStream stream(&file);
        if(stream.version() != QDataStream::Qt_6_7) { // for deserilizaiton, version must be same of that serilizaiton's version
            file.close();
            return false;
        }

        uint8_t age;
        QString name;
        float weight;

        stream >> age; // Streaming order is important
        stream >> name;
        stream >> weight;

        file.close();

        qInfo() << "Name " << name;
        qInfo() << "Age " << age;
        qInfo() << "Weight " << weight;
        
        return true;
    }
public:
    inline void run () {
        QString filename = "text.txt";
        QFile file(filename);

        write(file);
        read(file);
    }
};

#endif // DATASTREAM_H