#ifndef QBLOCKINGQUEUE_H
#define QBLOCKINGQUEUE_H


// QBlockingQueue.h
#include <QList>
#include <QMutex>
#include <QWaitCondition>

template <typename T>
class QBlockingQueue
{
public:
    QBlockingQueue();
    void push_back(const T& data);
    T pop_front();
private:
    QList<T> m_oList;
    QMutex m_oMutex;
    QWaitCondition m_oWaitCondition;
};

#endif // QBLOCKINGQUEUE_H
