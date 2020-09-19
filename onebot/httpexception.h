#ifndef HTTPEXCEPTION_H
#define HTTPEXCEPTION_H

#include <QtNetwork>
class HttpException:QException
{
    Q_OBJECT
public:
    HttpException(QString errmsg_);
    //错误信息
    QString errmsg;
};

#endif // HTTPEXCEPTION_H
