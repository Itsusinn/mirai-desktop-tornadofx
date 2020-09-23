#include "bytearrayconverter.h"

ByteArrayConverter::ByteArrayConverter()
{

}
Event ByteArrayConverter::convert(QByteArray metaData){
    QJsonDocument documentData = QJsonDocument::fromJson(metaData);
    QJsonObject data = documentData.object();
    QString postType = data.value("post_type").toString();
    if(postType == "private"){
        return PrivateMessageEvent()
    }
}
void ByteArrayConverter::run(){

}
