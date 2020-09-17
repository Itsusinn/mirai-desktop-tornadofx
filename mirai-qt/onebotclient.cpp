#include "onebotclient.h"

OneBotClient::OneBotClient()
{
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),
            this,SLOT(replyFinished(QNetworkReply*)));
}
void OneBotClient::replyFinished(QNetworkReply *reply){
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QString all = codec->toUnicode(reply->readAll());
}

QNetworkRequest OneBotClient::createRequest(QString api,QString content){

    QNetworkRequest request = QNetworkRequest(QUrl("http://127.0.0.1:5700/"));
    request.setRawHeader("Authorization","Bearer "+token);
    request.setHeader(QNetworkRequest::KnownHeaders::ContentTypeHeader,"application/json");
    return request;
}
