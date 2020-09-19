#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <QtNetwork>
#include <QWebSocket>

class WebsocketClient : public QObject
{
    Q_OBJECT
public:
    explicit WebsocketClient(QObject *parent = nullptr);
private:
    QWebSocket  *websocket;

signals:
private slots:
    //断开连接后执行方法
    void onDisconnected();

    //连接成功后执行方法
    void onConnected();

    //收到数据后执行方法（此处为收到二进制数据方法）
    void onBinaryMessageReceived(QByteArray message);

    // //收到数据后执行方法（此处为收到字符数据方法）
    // void onTextMessageReceived(QString message);

    //需要重连时执行方法
    void reconnect();

};

#endif // WEBSOCKETCLIENT_H
