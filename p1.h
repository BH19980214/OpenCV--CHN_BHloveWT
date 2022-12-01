#pragma once
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

#ifndef DLL_IMPORT
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif


class API InterfaceClass
{
public:
  virtual void find_shape_models(Mat m, Mat p) = 0;
  virtual Mat return_Mat() = 0;
  virtual int return_Mrcx() = 0;
  virtual int return_Mrcy() = 0;
  virtual int return_leftX() = 0;
  virtual int return_leftY() = 0;
  virtual int return_rightX() = 0;
  virtual int return_rightY() = 0;
};
class ExportedClass :public InterfaceClass
{
public:
  virtual void find_shape_models(Mat m, Mat p) override;
  virtual Mat return_Mat() override;
  virtual int return_Mrcx() override;
  virtual int return_Mrcy() override;
  virtual int return_leftX() override;
  virtual int return_leftY() override;
  virtual int return_rightX() override;
  virtual int return_rightY() override;
};
extern "C" API InterfaceClass * getInstance();
