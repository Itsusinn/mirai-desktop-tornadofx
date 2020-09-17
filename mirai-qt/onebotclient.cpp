#include "onebotclient.h"

#include <iostream>

OneBotClient::OneBotClient()
{
    manager = new QNetworkAccessManager(this);
}
