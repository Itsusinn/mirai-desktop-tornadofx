#ifndef EVENT_H
#define EVENT_H

#include <QObject>

class Event
{
public:
    Event();
//    virtual QJsonDocument toJson() = 0;
    QString time;
    QString self_id;
    QString post_type;
signals:

};
//消息事件
class MessageEvent : public Event
{
public:
    QString message_type;
    QString sub_type;
    QString message_id;
    QString user_id;
    QString message;
    QString raw_message;
    QString font;
    QString sender;
};
//提醒事件
class NoticeEvent : public Event
{
public:

};
//请求事件
class RequestEvent : public Event{
public:
};
//元事件
class MetaEvent : public Event{
public:
};


#endif // EVENT_H

