#ifndef CONVERT_MAT_QIMAGE_H
#define CONVERT_MAT_QIMAGE_H

#include <QObject>
#include <opencv2/opencv.hpp>
using namespace cv;
class convert_Mat_Qimage : public QObject
{
    Q_OBJECT
public:
    explicit convert_Mat_Qimage(QObject *parent = nullptr);
    Mat QImage2cvMat(QImage image);
    QImage cvMat2QImage(const Mat& mat);
    Mat QImage2cvMat1(QImage *image);
signals:

};

#endif // CONVERT_MAT_QIMAGE_H
