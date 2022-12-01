#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QAction>
#include <QFileDialog>
#include <QPushButton>
#include "p1.h"
#include "number_find.h"
#include <QStringList>
#include <QThread>
#include <QTimer>
#include <QDebug>
#include <iomanip>
#include "standardization_window.h"
#include "ui_standardization_window.h"
#include "txtname.h"
#include "ui_txtname.h"
#include "choose_number.h"
#include "ui_choose_number.h"
#include <QPushButton>
#include <QPainter>
#include <QPen>
#include <QLabel>
#include <QMessageBox>

using namespace cv;
using namespace std;
cv::Rect rex;
cv::Mat roi;
extern double w;
extern double h;
extern bool isSetModel;
extern QString IP;
extern int Port;
extern double angle_Pulse;
extern double OFFX;
int PLC_x;
int PLC_y;
int auto_num;

int thresh = 200;
int rcx1;
int rcy1;
int leftX;
int leftY;
int rightX;
int rightY;
Mat templ_show;

void find_shape_models(Mat templ, Mat match);
Mat convertTo3Channels(const Mat& binImg);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_show_roi->setScaledContents(true);
    ui->label_pic->setScaledContents(true);
    label_create = ui->label_pic;
    new_window = new standardization_window;
    new_txtName = new TxtName;
    new_choose = new choose_number;
    plc_modbus = new MyModbus;
    //线程对象实例化
    myThread=new MyThread();
    AutoThread = new autoThread();
    //将线程中的信号与槽进行连接
    connect(myThread,SIGNAL(mess()),this,SLOT(display()));
    IP = ui->le_IP->text();
    Port = ui->le_Port->text().toInt();
    path =  QDir::currentPath()+"/model.txt";
    load_txt();
    num_find = 0;
    num_all = 0;

    //载入
    connect(ui->action_open,&QAction::triggered,this,[=]()
    {
        load_txt();
    });
    //保存
    connect(ui->action_save,&QAction::triggered,this,[=]()
    {
        save_txt();
    });

    //标定
    connect(new_window->ui->pb_standardization,&QPushButton::clicked,new_window,[=]()
    {
        on_btn_Trigger();
        number_tool = 0;
        more_Find();
        new_window->ui->le_standardization->setText(QString::number(standardization,'f',2));

    });

    //旋转确定
    connect(new_window->ui->pb_isTrue,&QPushButton::clicked,new_window,[=]()
    {
        is_standardization = standardization;
        ui->led_r->setText(QString::number(is_standardization));
        double_txt(4,is_standardization);

    });

    //第一个点
    connect(new_window->ui->pb_first,&QPushButton::clicked,new_window,[=]()
    {
        on_btn_Trigger();
        more_Find();

    });

    //第二个点
    connect(new_window->ui->pb_second,&QPushButton::clicked,new_window,[=]()
    {
        on_btn_Trigger();
        more_Find();
    });

    //X确定
    connect(new_window->ui->pb_true,&QPushButton::clicked,new_window,[=]()
    {
        is_stand_X = stand_X;
        ui->led_dx->setText(QString::number(is_stand_X));
        double_txt(13,is_stand_X);
    });

    connect(new_choose->ui->pb_choose_sure,&QPushButton::clicked,new_choose,[=]()
    {
        QString dir_str = QDir::currentPath();
        QString single_load_path = QFileDialog::getOpenFileName(this,dir_str);
        int number = new_choose->ui->le_choose_number->text().toInt();
        single_load_first(single_load_path);

        new_choose->close();
        QStringList list = single_load_path.split("/");
        QStringList list1 = list[4].split(".");
        ui->led_x1->setText(qb_single_load[0]);
        templ_X = ui->led_x1->text().toInt();
        ui->led_y1->setText(qb_single_load[2]);
        templ_Y = ui->led_y1->text().toInt();
        ui->led_x1_2->setText(qb_single_load[1]);
        templ_PLC_X =  ui->led_x1_2->text().toInt();
        ui->led_y1_2->setText(qb_single_load[3]);
        templ_PLC_Y =  ui->led_y1_2->text().toInt();
        qb[0] = qb_single_load[0];
        qb[1] = qb_single_load[2];
        qb[2] = qb_single_load[1];
        qb[3] = qb_single_load[3];
        qb[6] = (list1[0]+"\n").toUtf8();
        ui->le_work3->setText(list1[0]);
    });

    //保存单个模板
    connect(new_txtName->ui->pb_true_flie_name,&QPushButton::clicked,new_txtName,[=]()
    {
        create_file(new_txtName->ui->le_fileName->text(),templ_X,templ_PLC_X,templ_Y,templ_PLC_Y,ui->le_expose->text().toInt(),ui->le_dist->text().toDouble(),roi_model);
        qb[6] = (new_txtName->ui->le_fileName->text()+ "\n").toUtf8();
        ui->le_work3->setText(new_txtName->ui->le_fileName->text());
        new_txtName->ui->le_fileName->text().clear();
        new_txtName->close();
    });

    //自动运行
    connect(ui->action_auto,&QAction::triggered,this,[=]()
    {
        AutoThread->start();
    });

    //暂停
    connect(ui->action_stop,&QAction::triggered,this,[=]()
    {
        AutoThread->pause();
    });

    //继续
    connect(ui->action_continue,&QAction::triggered,this,[=]()
    {
        AutoThread->resume();
    });

    connect(AutoThread,&autoThread::emms,this,[=]()
    {
        auto_work();
    });

}


MainWindow::~MainWindow()
{
    save_txt();
    if(camera!=NULL)
    {

        camera->closeCamera();
       // delete camera;
    }
    delete ui;
}

//打开相机  并  实时图像
void MainWindow::on_btn_Connect()
{
    int expose = ui->le_expose->text().toInt();
    if(camera!=NULL)
    {
        camera->setExposureTime(expose);
    }
    if(camera==NULL)
    {
        camera=new Mycamera();
        //连接相机
        std::cout<<"Connect:  "<<camera->connectCamera("00792760583")<<std::endl;
        //设置为触发模式
        std::cout<<"TriggerMode:  "<<camera->setTriggerMode(1)<<std::endl;
        //设置触发源为软触发
        std::cout<<"TriggerSource:  "<<camera->setTriggerSource(7)<<std::endl;
        //设置曝光时间

        std::cout<<"SetExposureTime:  "<<camera->setExposureTime(expose)<<std::endl;
        //开启相机采集
        std::cout<<"StartCamera:  "<<camera->startCamera()<<std::endl;
        myThread->getCameraPtr(camera);
        myThread->getImagePtr(myImage);
    }
    runopen();
}

//采集单张图片
void MainWindow::on_btn_Trigger()
{
    image_single=new Mat();
    //发送软触发
    std::cout<<"SoftTrigger:  "<<camera->softTrigger()<<std::endl;
    //读取Mat格式的图像
    camera->ReadBuffer(*image_single);
    display(image_single);
    //释放指针
   // delete image_single;
}

//单张图片获取
void MainWindow::display(const Mat* imagePtr)
{
    std::cout<<"so"<<std::endl;
    //判断是黑白、彩色图像
    QmyImage_single=new QImage();
    if(imagePtr->channels()>1)
    {
        *QmyImage_single=QImage((const unsigned char*)(imagePtr->data),imagePtr->cols, imagePtr->rows, QImage::Format_RGB888);
    }
    else
    {
        *QmyImage_single=QImage((const unsigned char*)(imagePtr->data),imagePtr->cols, imagePtr->rows, QImage::Format_Indexed8);
    }

    //*QmyImage_single = (*QmyImage_single).scaled(label_create->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //显示图像
    label_create->setPixmap(QPixmap::fromImage(*QmyImage_single));

    w = (double)QmyImage_single->width()/(double)ui->label_pic->width();//获取比例宽
    h = (double)QmyImage_single->height()/(double)ui->label_pic->height();//获取比例高度
    qDebug()<<w;
    qDebug()<<h;
    //delete QmyImage_single;
}

void MainWindow::display()
{
    //判断是黑白、彩色图像
    QmyImage_more=new QImage();
    if(myImage->channels()>1)
    {
        *QmyImage_more=QImage((const unsigned char*)(myImage->data),myImage->cols, myImage->rows, QImage::Format_RGB888);
    }
    else
    {
        *QmyImage_more=QImage((const unsigned char*)(myImage->data),myImage->cols, myImage->rows, QImage::Format_Indexed8);
    }

    *QmyImage_more = (*QmyImage_more).scaled(ui->label_camera->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //显示图像
    ui->label_camera->setPixmap(QPixmap::fromImage(*QmyImage_more));
    delete QmyImage_more;
}

void MainWindow::runopen()
{
    if(!myThread->isRunning())
    {
        myThread->start();
    }
}

void MainWindow::openImage()
{
    QString curPath=QDir::currentPath();//获取系统当前目录
    QString dlgTitle="select Image"; //对话框标题
    QString filter="Image(*.jpg *.png *.bmp)"; //文件过滤器
    QString aFileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);//选择文件路径
    if(aFileName.isEmpty()) return;
    model = imread(string(aFileName.toLocal8Bit()));//读取Mat图片
    cvtColor(model,model,COLOR_BGR2GRAY);//模板转换灰度图
    img = QPixmap::fromImage(cMQ->cvMat2QImage(model));//Mat转换QImage再转QPixmap
    w = (double)img.width()/(double)ui->label_pic->width();//获取比例宽
    h = (double)img.height()/(double)ui->label_pic->height();//获取比例高度
    qDebug()<<w;
    qDebug()<<h;
}

void MainWindow::single_Find()
{
    try {
        ptr->find_shape_models(roi,*image_single);
        //find_shape_models(roi,*image_single);
        //cv::imshow("a",templ_show);
        QImage pi = cMQ->cvMat2QImage(ptr->return_Mat());
        label_create->setPixmap(QPixmap::fromImage(pi));
        ui->textEdit->append("模板工件X坐标："+QString::number(ptr->return_Mrcx()));
        ui->textEdit->append("模板工件Y坐标："+QString::number(ptr->return_Mrcy()));

        plc_modbus->readDevice();
        ui->textEdit->append("模板PLC坐标X："+QString::number(PLC_x));
        ui->textEdit->append("模板PLC坐标Y："+QString::number(PLC_y));

        roi_model = roi;
        templ_X = ptr->return_Mrcx();
        templ_Y = ptr->return_Mrcy();
        ui->led_x1->setText(QString::number(templ_X));
        ui->led_y1->setText(QString::number(templ_Y));
        templ_PLC_X = PLC_x;
        templ_PLC_Y = PLC_y;
        ui->led_x1_2->setText(QString::number(templ_PLC_X));
        ui->led_y1_2->setText(QString::number(templ_PLC_Y));
        //第一个模板的X
        single_txt(0,templ_X);
        //第一个模板的Y
        single_txt(1,templ_Y);
        //第一个PLC的X
        single_txt(2,templ_PLC_X);
        //第一个PLC的Y
        single_txt(3,templ_PLC_Y);
        new_txtName->show();

        if(ptr->return_Mrcx() == 0||ptr->return_Mrcy() == 0)
        {
            QMessageBox::information(this,"创建模板错误信息","视觉创建模板失败");
        }
        if(PLC_x == 0||PLC_y == 0)
        {
             QMessageBox::information(this,"创建模板错误信息","PLC读数失败");
        }
        apiClass->ThreeFindTemple(roi_model,*image_single,ui->le_min_threshold->text().toInt(),ui->le_max_threshold->text().toInt());
        temple_dist =apiClass->first_min_dist();
        ui->le_dist->setText(QString::number(temple_dist));

    } catch (...) {

    }
}

void MainWindow::more_Find()
{

    try{
        apiClass->ThreeFindTemple(roi_model,*image_single,ui->le_min_threshold->text().toInt(),ui->le_max_threshold->text().toInt());

        match_dist = apiClass->first_min_dist();
        ui->textEdit->append(QString::number(apiClass->first_min_dist()));

        ptr->find_shape_models(roi_model,*image_single);
        QImage pi = cMQ->cvMat2QImage(ptr->return_Mat());
        label_create->setPixmap(QPixmap::fromImage(pi));
        ui->textEdit->append("工件X坐标："+QString::number(ptr->return_Mrcx()));
        ui->textEdit->append("工件Y坐标："+QString::number(ptr->return_Mrcy()));
        match_X = ptr->return_Mrcx();
        match_Y = ptr->return_Mrcy();

        plc_modbus->readDevice();
        ui->textEdit->append("PLC坐标X："+QString::number(PLC_x));
        ui->textEdit->append("PLC坐标Y："+QString::number(PLC_y));

        if(match_dist>temple_dist)
        {
            ui->lb_OK_NG->setText("NG");
            ui->lb_OK_NG->setStyleSheet("color:red;");
            num_all++;
            ui->le_num_all->setText(QString::number(num_all));
        }
        if(match_dist<temple_dist)
        {
            ui->lb_OK_NG->setText("OK");
            ui->lb_OK_NG->setStyleSheet("color:green;");
            num_find++;
            num_all++;
            ui->le_num_find->setText(QString::number(num_find));
            ui->le_num_all->setText(QString::number(num_all));
        }
        switch (number_tool) {
        case 0:
            standardization = abs(match_Y-templ_X);
            break;
        default:
            break;
        }
    }
    catch(...)
    {

    }
}

void MainWindow::load_txt()
{
    QString dir_str = QDir::currentPath();
    if(qb.count()>1)
    {
        qb.clear();
    }
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    while (!file.atEnd())
    {
        qb+=file.readLine();
    }
    //视觉XY坐标
    ui->led_x1->setText(qb[0]);
    templ_X = ui->led_x1->text().toInt();
    ui->led_y1->setText(qb[1]);
    templ_Y = ui->led_y1->text().toInt();
    //PLCXY坐标
    ui->led_x1_2->setText(qb[2]);
    templ_PLC_X =  ui->led_x1_2->text().toInt();
    ui->led_y1_2->setText(qb[3]);
    templ_PLC_Y =  ui->led_y1_2->text().toInt();
    //标定坐标
    ui->led_r->setText(qb[4]);
    is_standardization = ui->led_r->text().toInt();
    ui->led_dx->setText(qb[5]);
    is_stand_X = ui->led_dx->text().toDouble();
    //工件名称
    ui->le_work3->setText(qb[6]);
    //获取图片
    roi_model = cv::imread((dir_str+"/" + qb[6].trimmed() +".png").toStdString());
    cv::cvtColor(roi_model,roi_model,COLOR_BGR2GRAY);

    //曝光匹配分数阈值
    ui->le_expose->setText(qb[7]);
    ui->le_dist->setText(qb[8]);
    ui->le_min_threshold->setText(qb[9]);
    ui->le_max_threshold->setText(qb[10]);


    file.close();
    qb_save = qb;
}

void MainWindow::single_load_first(QString path)
{
    if(qb_single_load.count()>1)
    {
        qb_single_load.clear();
    }
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    while (!file.atEnd())
    {
        qb_single_load+=file.readLine();
    }
}


void MainWindow::save_txt()
{
    single_txt(7,ui->le_expose->text().toInt());
    double_txt(8,ui->le_dist->text().toDouble());
    single_txt(9,ui->le_min_threshold->text().toInt());
    single_txt(10,ui->le_max_threshold->text().toInt());
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    for(int i = 0;i<qb.count();i++)
    {
        file.write(qb[i]);
    }
}

void MainWindow::single_txt(int number, int data)
{
    qb[number] = QString::number(data).toUtf8();
    QString str;
    str.prepend(qb[number]);
    str = str + "\n";
    qb[number] = str.toUtf8();
}

void MainWindow::single_txt_single(int number, int data)
{
    qb_save[number] = QString::number(data).toUtf8();
    QString str;
    str.prepend(qb_save[number]);
    str = str + "\n";
    qb_save[number] = str.toUtf8();
}

void MainWindow::double_txt(int number, double data)
{
    qb[number] = QString::number(data).toUtf8();
    QString str;
    str.prepend(qb[number]);
    str = str + "\n";
    qb[number] = str.toUtf8();
}

void MainWindow::double_txt_single(int number, double data)
{
    qb_save[number] = QString::number(data).toUtf8();
    QString str;
    str.prepend(qb_save[number]);
    str = str + "\n";
    qb_save[number] = str.toUtf8();
}


void MainWindow::create_file(QString file,int vx,int px,int vy,int py,int expose,double dist,Mat roi_image)
{

    //创建temp-path文件夹
    QString dir_str = QDir::currentPath();
    // 检查目录是否存在，若不存在则新建
    QDir dir;
    if(!dir.exists(dir_str))
    {
        bool res = dir.mkpath(dir_str);
    }
    QFile temp_path(dir_str+"/" + file +".txt");
    String pyth_name = (dir_str+"/" + file +".png").toStdString();

    cv::imwrite(pyth_name,roi_image);
    //如果txt文件路径不存在
    if(!dir.exists(dir_str+"/temp.txt"))
    temp_path.open(QIODevice::WriteOnly);//创建txt

    single_txt_single(0,vx);
    single_txt_single(1,px);
    single_txt_single(2,vy);
    single_txt_single(3,py);
    single_txt_single(4,expose);
    double_txt_single(5,dist);
    for(int i = 0;i<6;i++)
    {
        temp_path.write(qb_save[i]);
    }

    new_txtName->close();

}



void MainWindow::auto_work()
{
     plc_modbus->readDevice();
     if(auto_num == 1)
     {
         on_btn_Trigger();
         more_Find();
     }
}
















void MainWindow::on_pb_openCamera_clicked()
{
    on_btn_Connect();
}

void MainWindow::on_pb_catchPic_clicked()
{
    on_btn_Trigger();
}

void MainWindow::on_pb_setTempl_clicked()
{
    isSetModel = true;
}


void MainWindow::on_pb_show_Templ_clicked()
{
    label_create->show_Model_Img(*image_single,ui->label_show_roi);
    //label_create->show_Model_Img(roi_first,ui->label_show_roi);
    //cv::imshow("aa",roi_first);
}


void MainWindow::on_pb_setTempl_XY_clicked()
{
    single_Find();
}


void MainWindow::on_pb_matchModel_clicked()
{
    more_Find();
}


void MainWindow::on_action_standardization_triggered()
{
    new_window->show();
}


void MainWindow::on_pb_toolSet_clicked()
{
    ui->sw_tool->setCurrentIndex(0);
}


void MainWindow::on_pb_engineerTool_clicked()
{
    ui->sw_tool->setCurrentIndex(1);
}


void MainWindow::on_pb_connect_clicked()
{
    plc_modbus->connect_device();

}


void MainWindow::on_pb_write_clicked()
{
    plc_modbus->on_writeTor();
}


void MainWindow::on_pushButton_clicked()
{
    plc_modbus->readDevice();
    ui->led_PLCX->setText(QString::number(PLC_x));
    ui->led_PLCY->setText(QString::number(PLC_y));
    ui->led_PLCY_3->setText(QString::number(auto_num));
}


void MainWindow::on_pb_setTempl_XY_2_clicked()
{
    single_Find();
}


void MainWindow::on_pb_setTempl_XY_3_clicked()
{
    single_Find();
}





void MainWindow::on_pushButton_2_clicked()
{
     plc_modbus->on_writeTor1();
}

void find_shape_models(Mat templ, Mat match)
{
  Mat result;
  match.copyTo(templ_show);
  int result_cols = match.cols - templ.cols + 1;
  int result_rows = match.rows - templ.rows + 1;
  result.create(result_cols, result_rows, CV_32FC1);
  matchTemplate(match, templ, result, 0);
  normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
  double minVal, MaxVal;
  Point minLoc, maxLoc, matchLoc;
  minMaxLoc(result, &minVal, &MaxVal, &minLoc, &maxLoc, Mat());
  matchLoc = minLoc;
  Rect rect(matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows));
  leftX = matchLoc.x;
  leftY = matchLoc.y;
  rightX = matchLoc.x + templ.cols;
  rightY = matchLoc.y + templ.rows;
  rcx1 = (matchLoc.x + matchLoc.x + templ.cols) / 2;
  rcy1 = (matchLoc.y + matchLoc.y + templ.rows) / 2;
  templ_show = convertTo3Channels(templ_show);
  rectangle(templ_show, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar(0, 0, 255), 2, 8, 0);

}
Mat convertTo3Channels(const Mat& binImg)
{
  Mat three_channel = Mat::zeros(binImg.rows, binImg.cols, CV_8UC3);
  vector<Mat> channels;
  for (int i = 0; i < 3; i++)
  {
    channels.push_back(binImg);
  }
  merge(channels, three_channel);
  return three_channel;
}


