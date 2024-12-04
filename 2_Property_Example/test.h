#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test : public QObject
{
    Q_OBJECT
    QString m_message{};

public:
    explicit Test(QObject *parent = nullptr);

    Q_PROPERTY(QString message READ getMessage WRITE setnMessage NOTIFY messageChanged)

    QString getMessage() const;
    void setMessage(const QString& message);

signals:
    void messageChanged(QString message);

};

#endif // TEST_H
