
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


enum flann_log_level_t
{
    FLANN_LOG_NONE = 0,
    FLANN_LOG_FATAL = 1,
    FLANN_LOG_ERROR = 2,
    FLANN_LOG_WARN = 3,
    FLANN_LOG_INFO = 4,
    FLANN_LOG_DEBUG = 5
};

enum flann_distance_t
{
    FLANN_DIST_EUCLIDEAN 			= 1,
    FLANN_DIST_L2 					= 1,
    FLANN_DIST_MANHATTAN 			= 2,
    FLANN_DIST_L1 					= 2,
    FLANN_DIST_MINKOWSKI 			= 3,
    FLANN_DIST_MAX   				= 4,
    FLANN_DIST_HIST_INTERSECT  		= 5,
    FLANN_DIST_HELLINGER 			= 6,
    FLANN_DIST_CHI_SQUARE		 	= 7,
    FLANN_DIST_KULLBACK_LEIBLER  	= 8,
    FLANN_DIST_HAMMING         		= 9,
    FLANN_DIST_HAMMING_LUT			= 10,
    FLANN_DIST_HAMMING_POPCNT   	= 11,
    FLANN_DIST_L2_SIMPLE	   		= 12,
};


#endif