#ifndef ONEBOTCLIENT_H
#define ONEBOTCLIENT_H

#include <QtNetwork>
#include "httpclient.h"
namespace mirai {

struct LoginInfo
{
    QString nickname;
    QString user_id;
};
}

class OnebotClient:public QObject
{
    Q_OBJECT
public:
    OnebotClient(QString server,qint64 account_,QString token_);

    //获取登录号信息
    mirai::LoginInfo get_login_info();

private:
    HttpClient *httpclient;
    QMap<QString,QString> headers;

    //onebot服务器地址 注意结尾有/
    QString server;

    //bot帐号
    qint64 account;

    //bot的token
    QString token;

};

#endif // ONEBOTCLIENT_H
