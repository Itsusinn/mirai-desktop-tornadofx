#include "httpclient.h"
#include <iostream>

#include <QDebug>

HttpClient::HttpClient()
{
    manager = new QNetworkAccessManager(this);
}
void HttpClient::sendRequest(QString path,QJsonDocument data){

    QNetworkRequest req;
    req.setUrl(QUrl("http://127.0.0.1:5700/"+path));
    req.setRawHeader("Accept", "application/json");
    req.setRawHeader("Content-Type", "application/json");
    req.setRawHeader("Authorization","Bearer WuzrSHRyB9NxO1m8");
    req.setRawHeader("X-Self-ID","3015420184");
    manager->post(req,data.toJson());

    connect(manager,SIGNAL(finished(QNetworkReply *)),
            this,SLOT(requestFinished(QNetworkReply *)));
}
void HttpClient::requestFinished(QNetworkReply* reply){
    QString result = QString::fromUtf8( reply->readAll());
    qDebug()<<result;
}
