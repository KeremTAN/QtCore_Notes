#include "station.h"


Station::Station(QObject *parent, int channel, QString name)  : QObject{parent}, channel{channel}, name{name}
{

}

void Station::broadcast(const QString &message) const
{
    emit send(this->channel, this->name, message);
}
