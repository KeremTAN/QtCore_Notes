#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>

class Source : public QObject
{
    Q_OBJECT
public:
    explicit Source(QObject *parent = nullptr);

    void publisher();

signals:
    void mySignal(const QString& message);
};

#endif // SOURCE_H
