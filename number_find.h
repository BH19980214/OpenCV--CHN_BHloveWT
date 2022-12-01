#pragma once
#pragma once
#include <opencv2\opencv.hpp>

using namespace cv;
using namespace std;

#ifndef DLL_IMPORT
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

class API APIClass
{
public:
  virtual void ThreeFindTemple(Mat first_roi, Mat second_roi, int min_threshold, int max_threshold) = 0;
  virtual double first_min_dist() = 0;
};

class ExportedClass_three :public APIClass
{
public:
  virtual void ThreeFindTemple(Mat first_roi, Mat match_image, int min_threshold, int max_threshold) override;
  virtual double first_min_dist() override;
};
extern "C" API APIClass * getAPI();
