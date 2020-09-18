#include "onebot.h"
#include <iostream>

#include <QDebug>

OnebotClient::OnebotClient(QString account_,QString token_)
{
    httpclient = new HttpClient();
    account = account_;
    token = token_;
    //设置请求头
    headers.insert("Content-Type","application/json");
    headers.insert("Authorization","Bear "+token);
    headers.insert("X-Self-ID",account);
}