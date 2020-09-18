#ifndef ONEBOTCLIENT_H
#define ONEBOTCLIENT_H

#include <QtNetwork>
#include "httpclient.h"


class OnebotClient:public QObject
{
    Q_OBJECT
public:
    OnebotClient(QString account_,QString token_);

private:
    HttpClient *httpclient;
    QMap<QString,QString> headers;

    QString account;
    QString token;

private slots:

};

#endif // ONEBOTCLIENT_H