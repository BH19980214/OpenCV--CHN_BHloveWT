
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

const int imageWidth = 1600;                             //����ͷ�ķֱ���  
const int imageHeight = 1200;
const int boardWidth = 7;                               //����Ľǵ���Ŀ  
const int boardHeight = 7;                              //����Ľǵ�����  
const int boardCorner = boardWidth * boardHeight;       //�ܵĽǵ�����  
const int frameNumber = 13;                             //����궨ʱ��Ҫ���õ�ͼ��֡��  
const int squareSize = 20;                              //�궨��ڰ׸��ӵĴ�С ��λmm  
const Size boardSize = Size(boardWidth, boardHeight);   //  

Mat intrinsic;                                          //����ڲ���  
Mat distortion_coeff;                                   //����������  
vector<Mat> rvecs;                                        //��ת����  
vector<Mat> tvecs;                                        //ƽ������  
vector<vector<Point2f>> corners;                        //����ͼ���ҵ��Ľǵ�ļ��� ��objRealPoint һһ��Ӧ  
vector<vector<Point3f>> objRealPoint;                   //����ͼ��Ľǵ��ʵ���������꼯��  


vector<Point2f> corner;                                   //ĳһ��ͼ���ҵ��Ľǵ�  

Mat rgbImage, grayImage;

/*����궨����ģ���ʵ����������*/
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

/*��������ĳ�ʼ���� Ҳ���Բ�����*/

void CalibrationEvaluate(void)//�궨�������������
{
  double err = 0;
  double total_err = 0;
  //calibrateCamera(objRealPoint, corners, Size(imageWidth, imageHeight), intrinsic, distortion_coeff, rvecs, tvecs, 0);
  cout << "ÿ��ͼ��Ķ�����" << endl;
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
    cout << "��" << i + 1 << "��ͼ���ƽ����" << err << "����" << endl;
  }
  cout << "����ƽ����" << total_err / (corners.size() + 1) << "����" << endl;
}

void guessCameraParam(void)
{
  /*�����ڴ�*/
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
  /*��������*/
  //cvSave("cameraMatrix.xml", &intrinsic);  
  //cvSave("cameraDistoration.xml", &distortion_coeff);  
  //cvSave("rotatoVector.xml", &rvecs);  
  //cvSave("translationVector.xml", &tvecs);  
  /*�������*/
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
  cout << "��Q�˳� ..." << endl;
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
    if (isFind == true) //���нǵ㶼���ҵ� ˵�����ͼ���ǿ��е�  
    {
      /*
      Size(5,5) �������ڵ�һ���С
      Size(-1,-1) ������һ��ߴ�
      TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 20, 0.1)������ֹ����
      */
      cornerSubPix(grayImage, corner, Size(5, 5), Size(-1, -1), TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 20, 0.1));
      drawChessboardCorners(rgbImage, boardSize, corner, isFind);
      namedWindow("chessboard", 0);
      imshow("chessboard", rgbImage);
      corners.push_back(corner);
      //string filename = "res\\image\\calibration";  
      //filename += goodFrameCount + ".jpg";  
      //cvSaveImage(filename.c_str(), &IplImage(rgbImage));       //�Ѻϸ��ͼƬ��������  

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
  ͼ��ɼ���� ��������ʼ����ͷ��У��
  calibrateCamera()
  ������� objectPoints  �ǵ��ʵ����������
  imagePoints   �ǵ��ͼ������
  imageSize     ͼ��Ĵ�С
  �������
  cameraMatrix  ������ڲξ���
  distCoeffs    ����Ļ������
  rvecs         ��תʸ��(�����)
  tvecs         ƽ��ʸ��(�������
  */

  /*����ʵ�ʳ�ʼ���� ����calibrateCamera�� ���flag = 0 Ҳ���Բ���������*/
  guessCameraParam();
  cout << "guess successful" << endl;
  /*����ʵ�ʵ�У�������ά����*/
  calRealPoint(objRealPoint, boardWidth, boardHeight, frameNumber, squareSize);
  cout << "cal real successful" << endl;
  /*�궨����ͷ*/
  calibrateCamera(objRealPoint, corners, Size(imageWidth, imageHeight), intrinsic, distortion_coeff, rvecs, tvecs, 0);
  cout << "calibration successful" << endl;
  /*���沢�������*/
  outputCameraParam();
  CalibrationEvaluate();
  cout << "out successful" << endl;

  /*��ʾ����У��Ч��*/
  Mat cImage;
  undistort(rgbImage, cImage, intrinsic, distortion_coeff);
  namedWindow("�������Corret", 0);
  imshow("�������Corret", cImage);
  cout << "Correct Image" << endl;
  cout << "Wait for Key" << endl;




  /********ͼ�����굽��������*******/
  int  image_idx = 9;
  Mat rotation_matrix = Mat(3, 3, CV_32FC1, Scalar::all(0));
  Rodrigues(rvecs[image_idx], rotation_matrix);

  ////�Լ�����һ����ת����
  //Mat rotation = (Mat_<double>(3, 3) << 0,1,0,-1,0,0,0,0,1);
  //rotation_matrix = rotation_matrix*rotation;
  ////�Լ�����һ����ת������

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



  /*��ʾһ��ԭͼ������֮����Ѱ�ҽǵ�*/
  char name[100];
  //sprintf_s(name, "%d.jpg", image_idx);
  sprintf_s(name, "chess%d.bmp", image_idx);

  Mat show_tuxiang_gray = imread(name, 0);//��ʾͼ��ǵ�
  Mat show_tuxiang_rgb = imread(name, 1);//��ʾͼ��ǵ�
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
  namedWindow("ͼ������ϵ", 0);
  imshow("ͼ������ϵ", show_rgb);




  /*���������Ľ��*/
  Point2f kk;
  vector<Point2f>shijie;
  for (int i = 0; i < boardCorner; i++)
  {
    int xe = corner[i].x;//ͼ���е�����x
    int ye = corner[i].y;//ͼ���е�����y
    kk.x = (a1 * xe + a2 * ye + a3) / (a7 * xe + a8 * ye + a9);//����������xֵ
    kk.y = (a4 * xe + a5 * ye + a6) / (a7 * xe + a8 * ye + a9);//����������Yֵ
    shijie.push_back(kk);

  }
  Mat show_shijie = Mat::zeros(480, 640, CV_8UC3);
  for (int i = 0; i < boardCorner; i++)
  {
    tem.x = cvRound(shijie[i].x) + 220;
    tem.y = cvRound(shijie[i].y) + 120;

    circle(show_shijie, tem, 3, Scalar(0, 0, 255), -1, 8);
  }
  imshow("���ص���������ϵ���н���", show_shijie);


  /*�Ա�û�н�����������Ľ��*/
  shijie.clear();
  for (int i = 0; i < boardCorner; i++)
  {
    int xe = corners[image_idx][i].x;//ͼ���е�����x
    int ye = corners[image_idx][i].y;//ͼ���е�����y
    kk.x = (a1 * xe + a2 * ye + a3) / (a7 * xe + a8 * ye + a9);//����������xֵ
    kk.y = (a4 * xe + a5 * ye + a6) / (a7 * xe + a8 * ye + a9);//����������Yֵ
    shijie.push_back(kk);

  }
  Mat show_shijie2 = Mat::zeros(480, 640, CV_8UC3);
  for (int i = 0; i < boardCorner; i++)
  {
    tem.x = cvRound(shijie[i].x) + 220;
    tem.y = cvRound(shijie[i].y) + 120;

    circle(show_shijie2, tem, 3, Scalar(0, 0, 255), -1, 8);
  }
  imshow("���ص���������ϵ-�޽���", show_shijie2);



  /*************ͼ�����굽�����������***********************/

  waitKey(0);
  system("pause");
  return 0;
}