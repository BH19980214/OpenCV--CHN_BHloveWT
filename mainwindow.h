#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mylabel.h"
#include <QFileDialog>
#include <QPixmap>
#include "convert_mat_qimage.h"
#include "p1.h"
#include "number_find.h"
#include "mythread.h"
#include "mycamera.h"
#include "standardization_window.h"
#include "txtname.h"
#include "choose_number.h"
#include <QLabel>
#include "mymodbus.h"
#include <QByteArray>
#include "autothread.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    myLabel *label_create;
    standardization_window * new_window;
    TxtName * new_txtName;
    choose_number * new_choose;
    MyModbus *plc_modbus;
private:
    Ui::MainWindow *ui;
    void openImage();
    void single_Find();
    void more_Find();

    QPixmap img;
    QImage* QmyImage_more;
    QImage* QmyImage_single;
    convert_Mat_Qimage *cMQ;
    Mat model;
    //Mat find;
    //QStringList aFileNames;
    //匹配坐标确认
    InterfaceClass *ptr = getInstance();
    //匹配分数确认
    APIClass* apiClass = getAPI();

    Mat* image_single;
    int templ_X;
    int templ_Y;
    int templ_PLC_X;
    int templ_PLC_Y;

    int match_X;
    int match_Y;
    int match_PLC_X;
    int match_PLC_Y;

    double angle;
    double OFF_X;
    double standardization;
    double is_standardization;
    int number_single;
    int number_more;

    double stand_X;
    double is_stand_X;
    QString path;
    QList<QByteArray> qb;
    QList<QByteArray> qb_save;
    QList<QByteArray> qb_single_load;
    Mat roi_model;

    int num_find;
    int num_all;

    int number_tool;
    double temple_dist;
    double match_dist;

    //连接相机
    void on_btn_Connect();
    //采集单张图像
    void on_btn_Trigger();
    //用于显示单张图像
    void display(const Mat* image);

    //连续采集
    void runopen();
    //载入
    void load_txt();
    //保存
    void save_txt();
    //单个保存数据
    void single_txt(int number,int data);
    void double_txt(int number,double data);
    void single_txt_single(int number,int data);
    void double_txt_single(int number,double data);
    void create_file(QString file,int vx,int px,int vy,int py,int expose,double dist,Mat roi_image);
    void single_load_first(QString path);

    void auto_work();

    //相机指针
    CameraInterface* camera=NULL;
    //线程对象
    MyThread* myThread=NULL;
    autoThread *AutoThread = NULL;
    //用于保存图像的图像指针对象
    Mat* myImage=new Mat();


private slots:
    //显示连续图像
    void display();
    void on_pb_openCamera_clicked();
    void on_pb_catchPic_clicked();
    void on_pb_setTempl_clicked();
    void on_pb_show_Templ_clicked();
    void on_pb_setTempl_XY_clicked();
    void on_pb_matchModel_clicked();
    void on_action_standardization_triggered();
    void on_pb_toolSet_clicked();
    void on_pb_engineerTool_clicked();
    void on_pb_connect_clicked();
    void on_pb_write_clicked();
    void on_pushButton_clicked();
    void on_pb_setTempl_XY_2_clicked();
    void on_pb_setTempl_XY_3_clicked();
    void on_pushButton_2_clicked();
};
#endif // MAINWINDOW_H
