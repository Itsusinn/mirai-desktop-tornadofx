#ifndef MESSAGEEVENT_H
#define MESSAGEEVENT_H
#include "event.h"
//私聊事件
class PrivateMessageEvent : public MessageEvent
{
public:
    PrivateMessageEvent();
};

//好友私聊事件
class FriendMessageEvent : public PrivateMessageEvent{
public:
    FriendMessageEvent(QString time,
                       QString self_id,
                       QString message_id,
                       QString user_id,
                       QString message,
                       QString raw_message,
                       QString font,
                       QString sender);
};

//群临时会话
class TempMessageEvent : public PrivateMessageEvent{
public:
    TempMessageEvent(QString time,
                     QString self_id,
                     QString message_id,
                     QString user_id,
                     QString message,
                     QString raw_message,
                     QString font,
                     QString sender);
};



//群聊事件
class GroupMessageEvent : public MessageEvent{
public:
    GroupMessageEvent();
    QString group_id;
    QString anonymous;
};
//正常群消息
class NormalGroupMessageEvent : public GroupMessageEvent{
public:
    NormalGroupMessageEvent(QString time,
                            QString self_id,
                            QString message_id,
                            QString group_id,
                            QString user_id,
                            QString anonymous,
                            QString message,
                            QString raw_message,
                            QString font,
                            QString sender);
};
//匿名消息
class AnonymousGroupMessageEvent : public GroupMessageEvent{
public:
    AnonymousGroupMessageEvent(QString time,
                               QString self_id,
                               QString message_id,
                               QString group_id,
                               QString user_id,
                               QString anonymous,
                               QString message,
                               QString raw_message,
                               QString font,
                               QString sender);
};
//群内系统提示
class NoticeGroupMessageEvent : public GroupMessageEvent{
public:
    NoticeGroupMessageEvent(QString time,
                            QString self_id,
                            QString message_id,
                            QString group_id,
                            QString user_id,
                            QString anonymous,
                            QString message,
                            QString raw_message,
                            QString font,
                            QString sender);
};

#endif // MESSAGEEVENT_H
