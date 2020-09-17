#ifndef ONEBOTCLIENT_H
#define ONEBOTCLIENT_H

#include <QtNetwork>


class OneBotClient:QObject
{
public:
    OneBotClient();

    //设置token
    void setToken(QByteArray _token){
        token = _token;
    }

    //获取好友列表
    void getFriendsList();

private:

    QNetworkAccessManager *manager;
    //token 鉴权用
    QByteArray token;

};

#endif // ONEBOTCLIENT_H
