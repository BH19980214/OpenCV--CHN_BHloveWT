#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
#include "opencv2/opencv.hpp"
using namespace cv;

extern cv::Rect rex;
extern cv::Mat roi;
double w;
double h;
bool isSetModel;

myLabel::myLabel(QWidget *parent)
    : QLabel{parent}
{
    QPixmap img("D:/a.bmp");
    this->setScaledContents(true);
}

//鼠标按压事件
void myLabel::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton & isSetModel == true)
    {
        m_isDown =true;
        m_start_pos = e->pos();
        m_stop_pos = e->pos();
        qDebug()<<e->x()<<e->y();
    }
    if(e->button()==Qt::RightButton & isSetModel == true)
    {
        isSetModel = false;
    }
}

//鼠标松开事件
void myLabel::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton & isSetModel == true)
    {
        m_isDown = false;
        qDebug()<<e->x()<<e->y();
    }
}

//鼠标移动事件
void myLabel::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons()&Qt::LeftButton&m_isDown & isSetModel == true)
    {
        m_stop_pos = e->pos();
        qDebug()<<e->x()<<e->y();
    }
    update();
}

//画矩形事件
void myLabel::paintEvent(QPaintEvent *e)
{
    QLabel::paintEvent(e);
    QPainter painter(this);
    painter.setPen(QPen(Qt::red,2));
    if(!m_isDown)
    {
        return;
    }
    painter.drawRect(QRect(m_start_pos,m_stop_pos));
    rex = Rect(m_start_pos, m_stop_pos);

}

//获取鼠标事件矩形
cv::Rect myLabel::Rect(const QPoint &beginPoint, const QPoint &endPoint)
{
    int x, y, width, height;
    width = qAbs(beginPoint.x() - endPoint.x());
    height = qAbs(beginPoint.y() - endPoint.y());
    x = beginPoint.x() < endPoint.x() ? beginPoint.x() : endPoint.x();
    y = beginPoint.y() < endPoint.y() ? beginPoint.y() : endPoint.y();
    cv::Rect rect(x*w, y*h, width*w, height*h);
    return rect;
}
void myLabel::show_Model_Img(Mat model,QLabel *labelOut)
{
    cMQ = new convert_Mat_Qimage();
    roi = model.clone()(rex);
    labelOut->setPixmap(QPixmap::fromImage(cMQ->cvMat2QImage(roi)));
}




