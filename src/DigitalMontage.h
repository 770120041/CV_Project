#ifndef __DIGITAL_MONTAGE_H__
#define __DIGITAL_MONTAGE_H__

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#include "Util.h"
#include "Constants.h"
#include "DataCost.h"

// libs for math calculation
#include "GCoptimization.h"
#include "Eigen/Sparse"
#include "Eigen/SparseCholesky"


#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <pthread.h>
#include <cmath>

// params for each thread
struct thread_param {
    int id;
    int channel_idx;
    int constraint;
    const Mat &gradientAtX;
    const Mat &gradientAtY;
    Mat &output;
};


class DigitalMontage {
public:
    void Run(const vector<Mat> &Images, const Mat &Label, int mode = USER_SPECIFY, double user_coe = 0);

private:
    int currentMode;


    void calGradientDomainFusion(const vector<Mat> &Images, const Mat &ResultLabel);

    static void
    SolveForOneThread(int channel_idx, int constraint, const Mat &color_gradient_x, const Mat &color_gradient_y,
                      Mat &output);

    static void *thread_function(void *arg_raw) {
        struct thread_param *arg = (struct thread_param *) arg_raw;
        char logbuffer[1024];
        SolveForOneThread(arg->channel_idx, arg->constraint, arg->gradientAtX, arg->gradientAtY, arg->output);
        return ((void *) 0);
    }

    void SaveCompositeImage(const Mat &ResultLabel, const vector<Mat> &Images) {
        Mat composite_image(ResultLabel.rows, ResultLabel.cols, CV_8UC3);
        for (int y = 0; y < ResultLabel.rows; y++) {
            for (int x = 0; x < ResultLabel.cols; x++) {
                composite_image.at<Vec3b>(y, x) = Images[ResultLabel.at<uchar>(y, x)].at<Vec3b>(y, x);
            }
        }
        imwrite("compositeimage.png", composite_image);
    }

    void SaveResultLabel(const cv::Mat &ResultLabel, int n_label) {
        int width = ResultLabel.cols;
        int height = ResultLabel.rows;
        Mat color_result_map(height, width, CV_8UC3);
        std::vector<Vec3b> label_colors;
        for (int i = 0; i < n_label; i++) {
            label_colors.push_back(Vec3b(rand() % 256, rand() % 256, rand() % 256));
        }
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (int(ResultLabel.at<char>(y, x)) == LABEL_UNDEFINED) {
                    color_result_map.at<Vec3b>(y, x) = 0;
                } else {
                    color_result_map.at<Vec3b>(y, x) = label_colors[ResultLabel.at<uchar>(y, x)];
                }
            }
        }
        imwrite("resultlabels.png", color_result_map);
    }

};


#endif // __DIGITAL_MONTAGE_H__