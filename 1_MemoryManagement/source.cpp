#include "source.h"

Source::Source(QObject *parent)
    : QObject{parent}
{}

void Source::publisher()
{
    emit mySignal("Hello My Listener");
}
