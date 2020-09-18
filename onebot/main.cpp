#include <QCoreApplication>

#include "onebot.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    OnebotClient* client = new OnebotClient("http://127.0.0.1:5700/","3025420184","WuzrSHRyB9NxO1m8");
    qDebug() << client->get_login_info();
    client->deleteLater();
    return a.exec();
    exit (0);
}
