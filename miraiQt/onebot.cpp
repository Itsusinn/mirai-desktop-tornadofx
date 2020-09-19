#include "onebot.h"
using namespace mirai;
OnebotClient::OnebotClient(QString server_,qint64 account_,QString token_)
{
    httpclient = new HttpClient();
    account = account_;
    token = token_;
    server = server_;
    //设置请求头
    headers.insert("Content-Type","application/json");
    headers.insert("Authorization","Bear "+token);
    headers.insert("X-Self-ID",QString::number(account));
}

mirai::LoginInfo OnebotClient::get_login_info(){
    QJsonObject body;
    QByteArray rawResult = httpclient->post(server+"get_login_info",headers,QJsonDocument(body));
    qDebug()<<rawResult;

    QJsonObject jsonResult = QJsonDocument::fromJson(rawResult).object();

    QString status = jsonResult.value("ststus").toString();
    if (status == "ok")
    {
        qDebug()<<"OnebotAPI操作成功";
    }else if (status == "async")
    {
        qDebug()<<"async";
        /* code */
    }else if (status == "failed")
    {
        throw "failed";
    }
    mirai::LoginInfo loginInfo;
    QJsonObject data = jsonResult.value("data").toObject();
    loginInfo.user_id = data.value("user_id").toString().toLongLong();
    loginInfo.nickname = data.value("user_id").toString();
    return loginInfo;
}
