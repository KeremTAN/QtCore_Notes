#include "radio.h"

Radio::Radio(QObject *parent)
    : QObject{parent}
{}

void Radio::listen(int channel, const QString &name, const QString& message)
{
    qInfo() << channel << " " << name << ": " << message;
}
