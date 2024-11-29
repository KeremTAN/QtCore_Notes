#include "destination.h"

Destination::Destination(QObject *parent)
    : QObject{parent}
{}

void Destination::mySlot(const QString &message)
{
    qInfo() << message;
}
