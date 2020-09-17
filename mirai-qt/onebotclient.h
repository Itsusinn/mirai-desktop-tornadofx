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

    //用于创建带特定请求头的QNetworkRequest对象
    QNetworkRequest createRequest(QString api,QString content);

private:

    QNetworkAccessManager *manager;
    //token 鉴权用
    QByteArray token;

private slots:
    void replyFinished(QNetworkReply *);
};

#endif // ONEBOTCLIENT_H
