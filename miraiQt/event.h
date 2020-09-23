#ifndef EVENT_H
#define EVENT_H

#include <QObject>

class Event : public QObject
{
    Q_OBJECT
public:
    Event();
    virtual QJsonDocument toJson() = 0;
    QString time;
    QString self_id;
    QString post_type;

signals:

};

class MessageEvent : public Event
{
    Q_OBJECT
public:
    MessageEvent();
    QString message_type;
    QString sub_type;
};

class NoticeEvent : public Event
{
    Q_OBJECT
public:
    NoticeEvent();

};

class RequestEvent : public Event{
    Q_OBJECT
public:
    RequestEvent();
};

class MetaEvent : public Event{
    Q_OBJECT
public:
    MetaEvent();
};


#endif // EVENT_H

