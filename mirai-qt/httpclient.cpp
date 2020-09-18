#include "httpclient.h"
#include <iostream>

#include <QDebug>

HttpClient::HttpClient()
{
    manager = new QNetworkAccessManager(this);
}
QByteArray HttpClient::post(const QString &strUrl,
                            const QMap<QByteArray,QByteArray> header,
                            const QJsonDocument body)
{
    assert(!strUrl.isEmpty());

    const QUrl url = QUrl::fromUserInput(strUrl);
    assert(url.isValid());

    //构建请求，头&体等
    QNetworkRequest qnr(url);

    //设置请求头
    QMapIterator<QByteArray, QByteArray> i(header); 
    while (i.hasNext())
    {
        i.next();
        qnr.setRawHeader(i.key(),i.value());
    }

    //异步地发送请求
    QNetworkReply* reply = manager->post(qnr,body.toJson());

    //创建loop转化为同步
    QEventLoop eventLoop;
    connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    eventLoop.exec(QEventLoop::ExcludeUserInputEvents);

    QByteArray replyData = reply->readAll();
    //TODO 对接onbot错误码
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    QVariant redirectAttr = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    //300qt错误
    if (reply->error()|| 300 == statusCode || !redirectAttr.isNull()){
        QString errString = reply->error() ? reply->errorString() : QString("发生重定向(%1)，不允许此情况").arg(statusCode);
        qDebug()<<(nullptr, "网络异常",
            QString("发送get请求时出现错误：\n网址：%1\n错误信息：%2").arg(reply->request().url().toDisplayString(), errString));
        replyData.clear();
    }
    reply->deleteLater();
    reply = nullptr;

    return replyData;

}
