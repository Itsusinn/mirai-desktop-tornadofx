#include "onebot.h"
#include <iostream>

#include <QDebug>

OnebotClient::OnebotClient()
{
    httpclient = new HttpClient();
}