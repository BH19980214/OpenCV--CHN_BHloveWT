#include "convert_mat_qimage.h"
#include <opencv2/opencv.hpp>
#include <QImage>
using namespace cv;
convert_Mat_Qimage::convert_Mat_Qimage(QObject *parent)
    : QObject{parent}
{

}
Mat convert_Mat_Qimage::QImage2cvMat(QImage image)
{
   // qDebug()<<image.format();
    cv::Mat mat;   //创建一个mat对象来接收
    switch (image.format())  //QImage 的一个库函数 可以返回图片的类型
    {
    case QImage::Format_ARGB32_Premultiplied:  //RGB32 为四通道的所以在调用mat构造函数需要转换成四通道的mat类型（CV_8UC4）
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:   //RGB888 即RGB24 三通道八位的图片 所以转成三通道的mat(CV_8UC4)
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        //因为Qimage 是RGB 通道 而 Mat 为 BGR 通道 所以需要使用cvtcolor进行转换，不然图片通道会颠倒
        cv::cvtColor(mat, mat,cv::COLOR_RGB2BGR);
        break;
    case QImage::Format_Indexed8:  //Indexed8 为单通道的图片 所以在转换成mat 也是单通道（CV_8UC1）
        mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    }
    return mat;
}
Mat convert_Mat_Qimage::QImage2cvMat1(QImage *image)
{
   // qDebug()<<image.format();
    cv::Mat mat;   //创建一个mat对象来接收
    switch (image->format())  //QImage 的一个库函数 可以返回图片的类型
    {
    case QImage::Format_ARGB32_Premultiplied:  //RGB32 为四通道的所以在调用mat构造函数需要转换成四通道的mat类型（CV_8UC4）
        mat = cv::Mat(image->height(), image->width(), CV_8UC4, (void*)image->constBits(), image->bytesPerLine());
        break;
    case QImage::Format_RGB888:   //RGB888 即RGB24 三通道八位的图片 所以转成三通道的mat(CV_8UC4)
        mat = cv::Mat(image->height(), image->width(), CV_8UC3, (void*)image->constBits(), image->bytesPerLine());
        //因为Qimage 是RGB 通道 而 Mat 为 BGR 通道 所以需要使用cvtcolor进行转换，不然图片通道会颠倒
        cv::cvtColor(mat, mat,cv::COLOR_RGB2BGR);
        break;
    case QImage::Format_Indexed8:  //Indexed8 为单通道的图片 所以在转换成mat 也是单通道（CV_8UC1）
        mat = cv::Mat(image->height(), image->width(), CV_8UC1, (void*)image->constBits(), image->bytesPerLine());
        break;
    }
    return mat;
}

QImage convert_Mat_Qimage::cvMat2QImage(const Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        // Set the color table (used to translate colour indexes to qRgb values)
        //image.setNumColors(256);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        return QImage();
    }
}
