#ifndef MYTHREAD_H
#define MYTHREAD_H
#include"QThread"
#include"camerainterface.h"
#include <QObject>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
     ~MyThread();
    void run();
    void getCameraPtr(CameraInterface* camera);
    void getImagePtr(cv::Mat* image);
signals:
    void mess();

private:
    CameraInterface* cameraPtr=NULL;
    cv::Mat* imagePtr=NULL;
};

#endif // MYTHREAD_H
