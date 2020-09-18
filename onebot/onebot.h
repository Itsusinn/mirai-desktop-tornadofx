#ifndef ONEBOTCLIENT_H
#define ONEBOTCLIENT_H

#include <QtNetwork>
#include "httpclient.h"

class OnebotClient:public QObject
{
    Q_OBJECT
public:
    OnebotClient(QString server,QString account_,QString token_);
    ~OnebotClient();

    //获取登录号信息
    QString get_login_info();

private:
    HttpClient *httpclient;
    QMap<QString,QString> headers;

    //onebot服务器地址 注意结尾有/
    QString server;

    //bot帐号
    QString account;

    //bot的token
    QString token;

};

#endif // ONEBOTCLIENT_H
