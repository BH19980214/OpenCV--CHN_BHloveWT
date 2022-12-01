#ifndef AUTOTHREAD_H
#define AUTOTHREAD_H

#include <QThread>
#include <QMutex>

class autoThread : public QThread
{
    Q_OBJECT
public:
    explicit autoThread(QObject *parent = nullptr);
    void run() override;
    void pause();
    void resume();
    void exitThread();
signals:
    void emms();
private:
    QMutex m_mutex;
};

#endif // AUTOTHREAD_H
