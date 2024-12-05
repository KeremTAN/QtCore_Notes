#ifndef STATION_H
#define STATION_H

#include <QObject>

class Station : public QObject
{
    Q_OBJECT
public:
    explicit Station(QObject *parent = nullptr, int channel=0, QString name = "unknown");


signals:
    void send(int channel, const QString& name, const QString& message) const;

public slots:
    void broadcast(const QString& message) const;

private:
    int channel{};
    QString name{};
};

#endif // STATION_H
