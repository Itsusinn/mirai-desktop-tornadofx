#include "messageevent.h"

PrivateMessageEvent::PrivateMessageEvent(){}
FriendMessageEvent::FriendMessageEvent(QString time_,
                                       QString self_id_,
                                       QString message_id_,
                                       QString user_id_,
                                       QString message_,
                                       QString raw_message_,
                                       QString font_,
                                       QString sender_)
{
    time = time_;
    self_id = self_id_;
    message_id = message_id_;
    user_id = user_id_;
    message = message_;
    raw_message = raw_message_;
    font = font_;
    sender = sender_;
}

TempMessageEvent::TempMessageEvent(QString time_,
                                   QString self_id_,
                                   QString message_id_,
                                   QString user_id_,
                                   QString message_,
                                   QString raw_message_,
                                   QString font_,
                                   QString sender_)
{
    time = time_;
    self_id = self_id_;
    message_id = message_id_;
    user_id = user_id_;
    message = message_;
    raw_message = raw_message_;
    font = font_;
    sender = sender_;
}


GroupMessageEvent::GroupMessageEvent(){}

NormalGroupMessageEvent::NormalGroupMessageEvent(QString time_,
                                                 QString self_id_,
                                                 QString message_id_,
                                                 QString group_id_,
                                                 QString user_id_,
                                                 QString anonymous_,
                                                 QString message_,
                                                 QString raw_message_,
                                                 QString font_,
                                                 QString sender_)
{
    time = time_;
    self_id = self_id_;
    message_id = message_id_;
    group_id = group_id_;
    user_id = user_id_;
    anonymous = anonymous_;
    message = message_;
    raw_message = raw_message_;
    font = font_;
    sender = sender_;
}
AnonymousGroupMessageEvent::AnonymousGroupMessageEvent(QString time_,
                                                       QString self_id_,
                                                       QString message_id_,
                                                       QString group_id_,
                                                       QString user_id_,
                                                       QString anonymous_,
                                                       QString message_,
                                                       QString raw_message_,
                                                       QString font_,
                                                       QString sender_)
{
    time = time_;
    self_id = self_id_;
    message_id = message_id_;
    group_id = group_id_;
    user_id = user_id_;
    anonymous = anonymous_;
    message = message_;
    raw_message = raw_message_;
    font = font_;
    sender = sender_;
}

NoticeGroupMessageEvent::NoticeGroupMessageEvent(QString time_,
                                                 QString self_id_,
                                                 QString message_id_,
                                                 QString group_id_,
                                                 QString user_id_,
                                                 QString anonymous_,
                                                 QString message_,
                                                 QString raw_message_,
                                                 QString font_,
                                                 QString sender_)
{
    time = time_;
    self_id = self_id_;
    message_id = message_id_;
    group_id = group_id_;
    user_id = user_id_;
    anonymous = anonymous_;
    message = message_;
    raw_message = raw_message_;
    font = font_;
    sender = sender_;
}
