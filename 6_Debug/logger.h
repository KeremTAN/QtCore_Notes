#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QDebug>
#include <QDateTime>
#include <QTextStream>
#include <QFile>
#include <QDir>
#include <iostream>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent = nullptr);

    static bool logging;
    static QString filename;

    static void attach();
    static void handler(QtMsgType type, const QMessageLogContext& context, const QString& msg);

signals:
};

#endif // LOGGER_H
