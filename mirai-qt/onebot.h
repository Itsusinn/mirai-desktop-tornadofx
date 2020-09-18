#ifndef ONEBOTCLIENT_H
#define ONEBOTCLIENT_H

#include <QtNetwork>
#include "httpclient.h"


class OnebotClient:public QObject
{
    Q_OBJECT
public:
    OnebotClient();
    OnebotClient(long account,QString token);
private:
    HttpClient *httpclient;
    long account;
    QString token;
private slots:

};

#endif // ONEBOTCLIENT_H