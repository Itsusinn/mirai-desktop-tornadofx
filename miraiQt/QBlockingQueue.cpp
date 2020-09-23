#include "QBlockingQueue.h"
// QBlockingQueue.cpp
template<typename T>
QBlockingQueue<T>::QBlockingQueue()
    : m_oList(),
    m_oMutex(),
    m_oWaitCondition()
{
}

// 首先判断队列是否为空，如果队列为空时，当加入新的数据时，调用条件等待的wakeAll唤醒
// 其他阻塞的读线程，如果有多个读线程，只能唤醒一个线程，唤醒线程的顺序一般先唤醒高优先级的,
// 如果优先级相同，则唤醒等待时间长的那个
template<typename T>
void QBlockingQueue<T>::push_back(const T &data)
{
    m_oMutex.lock();
    bool bEmpty = m_oList.empty();
    m_oList.push_back(data);
    m_oMutex.unlock();
    if (bEmpty)
        m_oWaitCondition.wakeAll();
}

// 当队列为空时等待，QWaitCondition还会释放QMutex(内部会调用unlock)
// 其他调用此方法的线程也阻塞在等待条件这里
template<typename T>
T QBlockingQueue<T>::pop_front()
{
    m_oMutex.lock();
    // 在这里应该使用while而不应该使用if
    // 因为操作系统有时会出现虚假唤醒
    while (m_oList.empty())
    {
        m_oWaitCondition(&m_oMutex);
    }
    T temp = m_oList.front();
    m_oList.pop_front();
    m_oMutex.unlock();
    return temp;
}
