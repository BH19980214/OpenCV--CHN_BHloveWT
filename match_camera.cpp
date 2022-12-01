
//#include <opencv2/opencv.hpp>  
//#include <highgui.hpp>  
//#include "cv.h"  
//#include <cv.hpp>  
//#include <iostream>  
//#include <tchar.h> 
//#include "atlstr.h" 

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/types_c.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

const int imageWidth = 1600;                             //摄像头的分辨率  
const int imageHeight = 1200;
const int boardWidth = 7;                               //横向的角点数目  
const int boardHeight = 7;                              //纵向的角点数据  
const int boardCorner = boardWidth * boardHeight;       //总的角点数据  
const int frameNumber = 13;                             //相机标定时需要采用的图像帧数  
const int squareSize = 20;                              //标定板黑白格子的大小 单位mm  
const Size boardSize = Size(boardWidth, boardHeight);   //  

Mat intrinsic;                                          //相机内参数  
Mat distortion_coeff;                                   //相机畸变参数  
vector<Mat> rvecs;                                        //旋转向量  
vector<Mat> tvecs;                                        //平移向量  
vector<vector<Point2f>> corners;                        //各个图像找到的角点的集合 和objRealPoint 一一对应  
vector<vector<Point3f>> objRealPoint;                   //各副图像的角点的实际物理坐标集合  


vector<Point2f> corner;                                   //某一副图像找到的角点  

Mat rgbImage, grayImage;

/*计算标定板上模块的实际物理坐标*/
void calRealPoint(vector<vector<Point3f>>& obj, int boardwidth, int boardheight, int imgNumber, int squaresize)
{
  //  Mat imgpoint(boardheight, boardwidth, CV_32FC3,Scalar(0,0,0));  
  vector<Point3f> imgpoint;
  for (int rowIndex = 0; rowIndex < boardheight; rowIndex++)
  {
    for (int colIndex = 0; colIndex < boardwidth; colIndex++)
    {
      //  imgpoint.at<Vec3f>(rowIndex, colIndex) = Vec3f(rowIndex * squaresize, colIndex*squaresize, 0);  
      imgpoint.push_back(Point3f(colIndex * squaresize, rowIndex * squaresize, 0));
    }
  }
  for (int imgIndex = 0; imgIndex < imgNumber; imgIndex++)
  {
    obj.push_back(imgpoint);
  }
}

/*设置相机的初始参数 也可以不估计*/

void CalibrationEvaluate(void)//标定结束后进行评价
{
  double err = 0;
  double total_err = 0;
  //calibrateCamera(objRealPoint, corners, Size(imageWidth, imageHeight), intrinsic, distortion_coeff, rvecs, tvecs, 0);
  cout << "每幅图像的定标误差：" << endl;
  for (int i = 0; i < corners.size(); i++)
  {
    vector<Point2f> image_points2;
    vector<Point3f> tempPointSet = objRealPoint[i];
    projectPoints(tempPointSet, rvecs[i], tvecs[i], intrinsic, distortion_coeff, image_points2);




    vector<Point2f> tempImagePoint = corners[i];
    Mat tempImagePointMat = Mat(1, tempImagePoint.size(), CV_32FC2);
    Mat image_points2Mat = Mat(1, image_points2.size(), CV_32FC2);
    for (int j = 0; j < tempImagePoint.size(); j++)
    {
      image_points2Mat.at<Vec2f>(0, j) = Vec2f(image_points2[j].x, image_points2[j].y);
      tempImagePointMat.at<Vec2f>(0, j) = Vec2f(tempImagePoint[j].x, tempImagePoint[j].y);
    }
    err = norm(image_points2Mat, tempImagePointMat, NORM_L2);
    total_err = err + total_err;
    cout << "第" << i + 1 << "幅图像的平均误差：" << err << "像素" << endl;
  }
  cout << "总体平均误差：" << total_err / (corners.size() + 1) << "像素" << endl;
}

void guessCameraParam(void)
{
  /*分配内存*/
  intrinsic.create(3, 3, CV_64FC1);
  distortion_coeff.create(5, 1, CV_64FC1);

  /*
  fx 0 cx
  0 fy cy
  0 0  1
  */
  intrinsic.at<double>(0, 0) = 256.8093262;   //fx         
  intrinsic.at<double>(0, 2) = 160.2826538;   //cx  
  intrinsic.at<double>(1, 1) = 254.7511139;   //fy  
  intrinsic.at<double>(1, 2) = 127.6264572;   //cy  

  intrinsic.at<double>(0, 1) = 0;
  intrinsic.at<double>(1, 0) = 0;
  intrinsic.at<double>(2, 0) = 0;
  intrinsic.at<double>(2, 1) = 0;
  intrinsic.at<double>(2, 2) = 1;

  /*
  k1 k2 p1 p2 p3
  */
  distortion_coeff.at<double>(0, 0) = -0.193740;  //k1  
  distortion_coeff.at<double>(1, 0) = -0.378588;  //k2  
  distortion_coeff.at<double>(2, 0) = 0.028980;   //p1  
  distortion_coeff.at<double>(3, 0) = 0.008136;   //p2  
  distortion_coeff.at<double>(4, 0) = 0;          //p3  
}

void outputCameraParam(void)
{
  /*保存数据*/
  //cvSave("cameraMatrix.xml", &intrinsic);  
  //cvSave("cameraDistoration.xml", &distortion_coeff);  
  //cvSave("rotatoVector.xml", &rvecs);  
  //cvSave("translationVector.xml", &tvecs);  
  /*输出数据*/
  cout << "fx :" << intrinsic.at<double>(0, 0) << endl << "fy :" << intrinsic.at<double>(1, 1) << endl;
  cout << "cx :" << intrinsic.at<double>(0, 2) << endl << "cy :" << intrinsic.at<double>(1, 2) << endl;

  cout << "k1 :" << distortion_coeff.at<double>(0, 0) << endl;
  cout << "k2 :" << distortion_coeff.at<double>(1, 0) << endl;
  cout << "p1 :" << distortion_coeff.at<double>(2, 0) << endl;
  cout << "p2 :" << distortion_coeff.at<double>(3, 0) << endl;
  cout << "p3 :" << distortion_coeff.at<double>(4, 0) << endl;
}

//int _tmain(int argc, _TCHAR* argv[])
int main()
{
  Mat img;
  int goodFrameCount = 0;
  namedWindow("chessboard",0);
  cout << "按Q退出 ..." << endl;
  while (goodFrameCount < frameNumber)
  {

    char filename[100];
    sprintf_s(filename, "chess%d.bmp", goodFrameCount);
    //sprintf_s(filename, "%d.jpg", goodFrameCount);
    goodFrameCount++;

    rgbImage = imread(filename, 1);
    cvtColor(rgbImage, grayImage, CV_BGR2GRAY);
    namedWindow("Camera", 0);
    imshow("Camera", grayImage);

    bool isFind = findChessboardCorners(rgbImage, boardSize, corner, 0);
    if (isFind == true) //所有角点都被找到 说明这幅图像是可行的  
    {
      /*
      Size(5,5) 搜索窗口的一半大小
      Size(-1,-1) 死区的一半尺寸
      TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 20, 0.1)迭代终止条件
      */
      cornerSubPix(grayImage, corner, Size(5, 5), Size(-1, -1), TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 20, 0.1));
      drawChessboardCorners(rgbImage, boardSize, corner, isFind);
      namedWindow("chessboard", 0);
      imshow("chessboard", rgbImage);
      corners.push_back(corner);
      //string filename = "res\\image\\calibration";  
      //filename += goodFrameCount + ".jpg";  
      //cvSaveImage(filename.c_str(), &IplImage(rgbImage));       //把合格的图片保存起来  

      cout << "The image is good" << endl;
    }
    else
    {
      cout << "The image is bad please try again" << endl;
    }
    //  cout << "Press any key to continue..." << endl;  
    //  waitKey(0);  

    if (waitKey(10) == 'q')
    {
      break;
    }
    //  imshow("chessboard", rgbImage);  
  }

  /*
  图像采集完毕 接下来开始摄像头的校正
  calibrateCamera()
  输入参数 objectPoints  角点的实际物理坐标
  imagePoints   角点的图像坐标
  imageSize     图像的大小
  输出参数
  cameraMatrix  相机的内参矩阵
  distCoeffs    相机的畸变参数
  rvecs         旋转矢量(外参数)
  tvecs         平移矢量(外参数）
  */

  /*设置实际初始参数 根据calibrateCamera来 如果flag = 0 也可以不进行设置*/
  guessCameraParam();
  cout << "guess successful" << endl;
  /*计算实际的校正点的三维坐标*/
  calRealPoint(objRealPoint, boardWidth, boardHeight, frameNumber, squareSize);
  cout << "cal real successful" << endl;
  /*标定摄像头*/
  calibrateCamera(objRealPoint, corners, Size(imageWidth, imageHeight), intrinsic, distortion_coeff, rvecs, tvecs, 0);
  cout << "calibration successful" << endl;
  /*保存并输出参数*/
  outputCameraParam();
  CalibrationEvaluate();
  cout << "out successful" << endl;

  /*显示畸变校正效果*/
  Mat cImage;
  undistort(rgbImage, cImage, intrinsic, distortion_coeff);
  namedWindow("畸变矫正Corret", 0);
  imshow("畸变矫正Corret", cImage);
  cout << "Correct Image" << endl;
  cout << "Wait for Key" << endl;




  /********图像坐标到世界坐标*******/
  int  image_idx = 9;
  Mat rotation_matrix = Mat(3, 3, CV_32FC1, Scalar::all(0));
  Rodrigues(rvecs[image_idx], rotation_matrix);

  ////自己加了一个旋转矩阵
  //Mat rotation = (Mat_<double>(3, 3) << 0,1,0,-1,0,0,0,0,1);
  //rotation_matrix = rotation_matrix*rotation;
  ////自己加了一个旋转矩阵，完

  cv::Mat H(3, 3, CV_32FC1, Scalar::all(0));
  cv::Mat translation_ve;
  tvecs[image_idx].copyTo(translation_ve);
  rotation_matrix.copyTo(H);
  H.at<double>(0, 2) = translation_ve.at<double>(0, 0);
  H.at<double>(1, 2) = translation_ve.at<double>(1, 0);
  H.at<double>(2, 2) = translation_ve.at<double>(2, 0);
  cv::Mat hu;
  hu = intrinsic * H;
  cv::Mat hu2 = hu.inv();
  double a1, a2, a3, a4, a5, a6, a7, a8, a9;
  a1 = hu2.at<double>(0, 0);
  a2 = hu2.at<double>(0, 1);
  a3 = hu2.at<double>(0, 2);
  a4 = hu2.at<double>(1, 0);
  a5 = hu2.at<double>(1, 1);
  a6 = hu2.at<double>(1, 2);
  a7 = hu2.at<double>(2, 0);
  a8 = hu2.at<double>(2, 1);
  a9 = hu2.at<double>(2, 2);



  /*显示一张原图，矫正之后，再寻找角点*/
  char name[100];
  //sprintf_s(name, "%d.jpg", image_idx);
  sprintf_s(name, "chess%d.bmp", image_idx);

  Mat show_tuxiang_gray = imread(name, 0);//显示图像角点
  Mat show_tuxiang_rgb = imread(name, 1);//显示图像角点
  Mat show_gray;
  Mat show_rgb;
  undistort(show_tuxiang_gray, show_gray, intrinsic, distortion_coeff);
  undistort(show_tuxiang_rgb, show_rgb, intrinsic, distortion_coeff);
  corner.clear();
  //bool isFind = findChessboardCorners(show_gray, boardSize, corner, 0);
  bool isFind = findChessboardCorners(show_gray, boardSize, corner, CALIB_CB_ADAPTIVE_THRESH + CALIB_CB_NORMALIZE_IMAGE + CALIB_CB_FAST_CHECK);
  //cornerSubPix(show_gray, corner, Size(5, 5), Size(-1, -1), TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 20, 0.1));
  cornerSubPix(show_gray, corner, Size(11, 11), Size(-1, -1), TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
  //drawChessboardCorners(show_rgb, boardSize, corner, isFind);
  Point tem;
  for (int i = 0; i < boardCorner; i++)
  {
    tem.x = cvRound(corner[i].x);
    tem.y = cvRound(corner[i].y);

    circle(show_rgb, tem, 3, Scalar(0, 0, 255), -1, 8);
  }
  namedWindow("图像坐标系", 0);
  imshow("图像坐标系", show_rgb);




  /*相机矫正后的结果*/
  Point2f kk;
  vector<Point2f>shijie;
  for (int i = 0; i < boardCorner; i++)
  {
    int xe = corner[i].x;//图像中点坐标x
    int ye = corner[i].y;//图像中点坐标y
    kk.x = (a1 * xe + a2 * ye + a3) / (a7 * xe + a8 * ye + a9);//世界坐标中x值
    kk.y = (a4 * xe + a5 * ye + a6) / (a7 * xe + a8 * ye + a9);//世界坐标中Y值
    shijie.push_back(kk);

  }
  Mat show_shijie = Mat::zeros(480, 640, CV_8UC3);
  for (int i = 0; i < boardCorner; i++)
  {
    tem.x = cvRound(shijie[i].x) + 220;
    tem.y = cvRound(shijie[i].y) + 120;

    circle(show_shijie, tem, 3, Scalar(0, 0, 255), -1, 8);
  }
  imshow("返回到世界坐标系—有矫正", show_shijie);


  /*对比没有进行相机矫正的结果*/
  shijie.clear();
  for (int i = 0; i < boardCorner; i++)
  {
    int xe = corners[image_idx][i].x;//图像中点坐标x
    int ye = corners[image_idx][i].y;//图像中点坐标y
    kk.x = (a1 * xe + a2 * ye + a3) / (a7 * xe + a8 * ye + a9);//世界坐标中x值
    kk.y = (a4 * xe + a5 * ye + a6) / (a7 * xe + a8 * ye + a9);//世界坐标中Y值
    shijie.push_back(kk);

  }
  Mat show_shijie2 = Mat::zeros(480, 640, CV_8UC3);
  for (int i = 0; i < boardCorner; i++)
  {
    tem.x = cvRound(shijie[i].x) + 220;
    tem.y = cvRound(shijie[i].y) + 120;

    circle(show_shijie2, tem, 3, Scalar(0, 0, 255), -1, 8);
  }
  imshow("返回到世界坐标系-无矫正", show_shijie2);



  /*************图像坐标到世界坐标结束***********************/

  waitKey(0);
  system("pause");
  return 0;
}