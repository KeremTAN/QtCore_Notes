#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{}

QString Test::getMessage() const
{
    return m_message;
}

void Test::setMessage(const QString &message)
{
    this->m_message = message;
    emit messageChanged(this->m_message);
}
