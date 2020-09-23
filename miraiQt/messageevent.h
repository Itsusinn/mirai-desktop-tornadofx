#ifndef MESSAGEEVENT_H
#define MESSAGEEVENT_H
#include "event.h"
//私聊事件
class PrivateMessageEvent : public MessageEvent
{
    Q_OBJECT
public:
    PrivateMessageEvent();
};

//好友私聊事件
class FriendMessageEvent : public PrivateMessageEvent{
    Q_OBJECT
public:
    FriendMessageEvent();
};

//群临时会话
class TempMessageEvent : public PrivateMessageEvent{
    Q_OBJECT
public:
    TempMessageEvent();
};

//群聊事件
class GroupMessageEvent : public MessageEvent{
    Q_OBJECT
public:
    GroupMessageEvent();
};
//正常群消息
class NormalGroupMessageEvent : public GroupMessageEvent{
    Q_OBJECT
public:
    NormalGroupMessageEvent();
};
//匿名消息
class AnonymousGroupMessageEvent : public GroupMessageEvent{
    Q_OBJECT
public:
    AnonymousGroupMessageEvent();
};
//群内系统提示
class NoticeGroupMessageEvent : public GroupMessageEvent{
    Q_OBJECT
public:
    NoticeGroupMessageEvent();
};

#endif // MESSAGEEVENT_H
