#include "httpclient.h"
#include <iostream>

#include <QDebug>

HttpClient::HttpClient()
{
    manager = new QNetworkAccessManager(this);
}
QByteArray HttpClient::post(const QString &strUrl,const QMap<QString,QString> header,const QJsonDocument body)
{
    assert(!strUrl.isEmpty());

    const QUrl url = QUrl::fromUserInput(strUrl);
    assert(url.isValid());

    //构建请求，头&体等
    QNetworkRequest qnr(url);

    //设置请求头
    QMapIterator<QString, QString> i(header);
    while (i.hasNext())
    {
        i.next();
        qnr.setRawHeader(i.key().toUtf8(),i.value().toUtf8());
    }

    //异步地发送请求
    QNetworkReply* reply = manager->post(qnr,body.toJson());

    //创建loop转化为同步
    QEventLoop eventLoop;
    QTimer timer;

    connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    connect(&timer,SIGNAL(timeout()),&eventLoop,SLOT(quit()));
    timer.start(1000);
    eventLoop.exec();

     //请求的结果
    QByteArray replyData = reply->readAll();
    //状态码
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    //异常chu'li
    if(statusCode != 200){
        switch (statusCode) {
        case 401:throw (HttpException("401:access token 未提供"));
        case 403:throw (HttpException("403:access token 不符合"));
        case 406:throw (HttpException("406:POST 请求的 Content-Type 不支持"));
        case 400:throw (HttpException("400:POST 请求的正文格式不正确"));
        case 404:throw (HttpException("404:API 不存在"));
        }
    }

    if (timer.isActive()){
        timer.stop();
    } else {
        reply->abort();
        qDebug().noquote()<<"发送get请求超时";
        replyData.clear();
    }
    reply->deleteLater();
    reply = nullptr;

    return replyData;

}
//发get请求
QByteArray HttpClient::get(const QString &strUrl,const QMap<QString,QString> header)
{
    assert(!strUrl.isEmpty());

    const QUrl url = QUrl::fromUserInput(strUrl);
    assert(url.isValid());

    //构建请求，头&体等
    QNetworkRequest qnr(url);

    //设置请求头
    QMapIterator<QString, QString> i(header);
    while (i.hasNext())
    {
        i.next();
        qnr.setRawHeader(i.key().toUtf8(),i.value().toUtf8());
    }

    //异步地发送请求
    QNetworkReply* reply = manager->get(qnr);

    //创建loop转化为同步
    QEventLoop eventLoop;
    QTimer timer;

    connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    connect(&timer,SIGNAL(timeout()),&eventLoop,SLOT(quit()));
    timer.start(1000);
    eventLoop.exec();
    //请求的结果
    QByteArray replyData = reply->readAll();
    //状态码
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if(statusCode != 200){
        switch (statusCode) {
        case 401:throw (HttpException("401:access token 未提供"));
        case 403:throw (HttpException("403:access token 不符合"));
        case 406:throw (HttpException("406:POST 请求的 Content-Type 不支持"));
        case 400:throw (HttpException("400:POST 请求的正文格式不正确"));
        case 404:throw (HttpException("404:API 不存在"));
        }
    }

    if (timer.isActive()){
        timer.stop();
    } else {
        reply->abort();
        qDebug().noquote()<<"发送get请求超时";
        replyData.clear();
    }

    reply->deleteLater();
    reply = nullptr;

    return replyData;
}
