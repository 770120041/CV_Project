
#ifndef DIGITAL_MONTAGE_UTIL_H
#define DIGITAL_MONTAGE_UTIL_H



#define DEBUG
#include "DigitalMontage.h"

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

#include <string>
#include <vector>
#include <cmath>

float ParseCoefficient(const char* );
int ParseMode(char *);
Mat ReadAndResize(string ,float);
void debug_print(string s);
Mat parseImageAndLabel(int argc, char* argv[],vector<Mat> &Inputs, bool);


double euc_dist(const Vec3b & a, const Vec3b & b);
double smoothFn(int point_a, int point_b, int LabelA, int LabelB, void * data);
void calculate_gradient_at_xy(const Mat & image,int x,int y,double grad[]);
void cal_color_gradient( const cv::Mat & Image, int x, int y, cv::Vec3f & grad_x, cv::Vec3f & grad_y );


struct ExtraData
{
    vector<Mat> Images;
    Mat Label;
    flann::Index * kdtree;
    int cur_mode;
    int user_param;
};
struct ExtraDataContrast
{
    ExtraData extra;
    vector<Mat> GaussianImages;
};

#endif