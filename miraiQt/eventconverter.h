#ifndef EVENTCONVERTER_H
#define EVENTCONVERTER_H
#include <QRunnable>
#include <event.h>
#include <QJsonDocument>

class EventConverter : public QRunnable
{
public:
    EventConverter();
    void run() override;

private:
    QByteArray convert(Event metaData);

};

#endif // EVENTCONVERTER_H
