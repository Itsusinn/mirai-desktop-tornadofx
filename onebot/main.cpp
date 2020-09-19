#include <QCoreApplication>

#include "onebot.h"
#include <iostream>

using namespace mirai;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    OnebotClient* client = new OnebotClient("http://127.0.0.1:5700/",3025420184,"WuzrSHRyB9NxO1m8");
    mirai::LoginInfo info = client->get_login_info();
    client->deleteLater();
    exit(0);
    return a.exec();
}
