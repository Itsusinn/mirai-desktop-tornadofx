#ifndef BYTEARRAYCONVERTER_H
#define BYTEARRAYCONVERTER_H

#include <QRunnable>
#include "event.h"
#include "messageevent.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class ByteArrayConverter : public QRunnable
{
public:
    ByteArrayConverter();
    Event convert(QByteArray metaData);
    void run() override;
};

#endif // BYTEARRAYCONVERTER_H
