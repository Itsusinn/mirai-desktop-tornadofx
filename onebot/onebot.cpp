#include "onebot.h"

OnebotClient::OnebotClient(QString server_,QString account_,QString token_)
{
    httpclient = new HttpClient();
    account = account_;
    token = token_;
    server = server_;
    //设置请求头
    headers.insert("Content-Type","application/json");
    headers.insert("Authorization","Bear "+token);
    headers.insert("X-Self-ID",account);
}

QString OnebotClient::get_login_info(){
    QJsonObject body;
    return httpclient->post(server+"get_login_info",headers,QJsonDocument(body));
}
OnebotClient::~OnebotClient(){
    httpclient->deleteLater();
}
