#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QtNetwork>


class HttpClient:public QObject
{
    Q_OBJECT
public:
    HttpClient();
    QByteArray post(const QString &strUrl,
                    const QMap<QByteArray,QByteArray> header,
                    const QJsonDocument body);
    QByteArray get(const QString &strUrl,
                    const QMap<QByteArray,QByteArray> header);
private:
    QNetworkAccessManager *manager;
};

#endif // HTTPCLIENT_H
