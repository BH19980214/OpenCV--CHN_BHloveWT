#ifndef MYLABEL_H
#define MYLABEL_H
#include <QLabel>
#include <QWidget>
#include "opencv2/opencv.hpp"
#include "convert_mat_qimage.h"
using namespace cv;

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *);
    cv::Rect Rect(const QPoint &beginPoint, const QPoint &endPoint);
    void show_Model_Img(Mat model,QLabel *labelOut);
private:
    bool m_isDown;
    QPoint m_start_pos;
    QPoint m_stop_pos;
    convert_Mat_Qimage *cMQ;

signals:
};

#endif // MYLABEL_H
