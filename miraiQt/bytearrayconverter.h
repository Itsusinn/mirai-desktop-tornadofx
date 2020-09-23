#ifndef BYTEARRAYCONVERTER_H
#define BYTEARRAYCONVERTER_H

#include <QRunnable>
#include "event.h"
#include <QJsonDocument>

class ByteArrayConverter : public QRunnable
{
public:
    ByteArrayConverter();
    Event convert(QByteArray metaData);
};

#endif // BYTEARRAYCONVERTER_H
