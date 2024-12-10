#ifndef TEXTSTREAM_H
#define TEXTSTREAM_H

#include <QFile>
#include <QDebug>


class TextStream {

    inline void write(QFile& file) {

        if(!file.isWritable()) {
            qInfo() << "Unable to write to file!";
            return;
        }

        QTextStream stream(&file);
        stream.setEncoding(QStringConverter::LastEncoding);

        stream.seek(file.size());
        for(int i{}; i < 5; i++) {
            stream << QString::number(i) << "-Item \r\n";
        }
        stream.flush();
        qInfo() << "File written";
    }

    inline void read(QFile& file) {

        if(!file.isReadable()) {
            qInfo() << "Unable to read to file!";
            return;
        }

        QTextStream stream(&file);
        stream.seek(0);
        while(!stream.atEnd()) {
            qInfo() << stream.readLine();
        }

    }
public:
    inline void run () {
        QString filename = "text.txt";
        QFile file(filename);

        if(file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            qInfo() << "Encoding: " << stream.encoding();

            write(file);
            read(file);
            file.close();
        }
        else {
            qInfo() << file.errorString();
        }
    }
};

#endif // TEXTSTREAM_H
