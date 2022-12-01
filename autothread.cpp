#include "autothread.h"

autoThread::autoThread(QObject *parent)
    : QThread{parent}
{

}
void autoThread::run()
{
    while (!isInterruptionRequested()) {
       m_mutex.lock();
       emms();
       m_mutex.unlock();
       msleep(200);
    }
}

void autoThread::pause()
{
    m_mutex.lock();
}

void autoThread::resume()
{
    m_mutex.unlock();
}
void autoThread::exitThread()
{
    requestInterruption();

    wait();

    delete this;
}
