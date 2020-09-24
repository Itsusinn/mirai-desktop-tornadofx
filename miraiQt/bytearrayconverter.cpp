#include "bytearrayconverter.h"

ByteArrayConverter::ByteArrayConverter()
{

}
Event ByteArrayConverter::convert(QByteArray metaData){
    QJsonDocument documentData = QJsonDocument::fromJson(metaData);
    QJsonObject data = documentData.object();
    QString postType = data.value("post_type").toString();
    if(postType == "message"){
        QString messageType = data.value("message_type").toString();
        QString subType = data.value("sub_type").toString();
        if(messageType == "private"){
            if(subType == "friend"){
                return FriendMessageEvent(data.value("time").toString(),
                                          data.value("self_id").toString(),
                                          data.value("message_id").toString(),
                                          data.value("user_id").toString(),
                                          data.value("message").toString(),
                                          data.value("raw_message").toString(),
                                          data.value("font").toString(),
                                          data.value("sender").toString());
            }else if(subType == "group"){
                return TempMessageEvent(data.value("time").toString(),
                                         data.value("self_id").toString(),
                                         data.value("message_id").toString(),
                                         data.value("user_id").toString(),
                                         data.value("message").toString(),
                                         data.value("raw_message").toString(),
                                         data.value("font").toString(),
                                         data.value("sender").toString());
            }
        }else if(messageType == "group"){
            if(subType == "normal"){
                return NormalGroupMessageEvent(data.value("time").toString(),
                                               data.value("self_id").toString(),
                                               data.value("message_id").toString(),
                                               data.value("group_id").toString(),
                                               data.value("user_id").toString(),
                                               data.value("anonymous").toString(),
                                               data.value("message").toString(),
                                               data.value("raw_message").toString(),
                                               data.value("font").toString(),
                                               data.value("sender").toString());
            }else if(subType == "anonymous"){
                return AnonymousGroupMessageEvent(data.value("time").toString(),
                                               data.value("self_id").toString(),
                                               data.value("message_id").toString(),
                                               data.value("group_id").toString(),
                                               data.value("user_id").toString(),
                                               data.value("anonymous").toString(),
                                               data.value("message").toString(),
                                               data.value("raw_message").toString(),
                                               data.value("font").toString(),
                                               data.value("sender").toString());

            }else if(subType == "notice"){
                return NoticeGroupMessageEvent(data.value("time").toString(),
                                               data.value("self_id").toString(),
                                               data.value("message_id").toString(),
                                               data.value("group_id").toString(),
                                               data.value("user_id").toString(),
                                               data.value("anonymous").toString(),
                                               data.value("message").toString(),
                                               data.value("raw_message").toString(),
                                               data.value("font").toString(),
                                               data.value("sender").toString());}
        }
    }else if (postType == "") {

    }
}
void ByteArrayConverter::run(){

}
