#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QtNetwork>


class HttpClient:public QObject
{
    Q_OBJECT
public:
    HttpClient();

    //用于发送请求
    void sendRequest(QString path,QJsonDocument data);
private:
    QNetworkAccessManager *manager;
private slots:
    void requestFinished(QNetworkReply* reply);

};

#endif // HTTPCLIENT_H
