#include <QCoreApplication>
#include <QRandomGenerator>
#include <QFile>
#include <QChar>

QString makeData() {
    QString data{};
    data.append("Unicode test");

    for(int i{}; i<10; i++) {
        int number = QRandomGenerator::global()->bounded(0x10FFFF) ; // 1112064 utf8 encoding capacity
        if (QChar::isHighSurrogate(number) || QChar::isLowSurrogate(number)) {
            // Surrogate pair karakterlerini atla
            continue;
        }
        data.append(QChar(number));
    }
    return data;
}

QString makeBase64() {
    QString data{};
    for(int i{}; i<10; i++) {
        data.append("Hello");
    }

    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QString data = makeData();
    // qInfo() << data;
    // QFile file("./data.txt");

    // if(file.open(QIODevice::WriteOnly)) {
    //     QTextStream stream(&file);
    //     stream.setEncoding(QStringConverter::Encoding::Utf16);
    //     stream << data;
    //     stream.flush();

    //     file.close();
    // }

    // qInfo() << "Done";
    // qInfo() << "UTF8: " << data;
    // qInfo() << "ASCII: " << data.toLatin1();

    QString data = makeBase64();
    QByteArray bytes(data.toUtf8());
    QByteArray encoded = bytes.toBase64();
    QByteArray decoded = QByteArray::fromBase64(encoded);

    qInfo() << "Encoded: " << encoded;
    qInfo(" -------------------------------- ");
    qInfo() << "Decoded: " << decoded;

    QByteArray bytesHex(data.toUtf8());
    QByteArray encodedHex = bytes.toHex();
    QByteArray decodedHex = QByteArray::fromHex(encodedHex);

    qInfo() << "Encoded: " << encodedHex;
    qInfo(" -------------------------------- ");
    qInfo() << "Decoded: " << decodedHex;
    return a.exec();
}
