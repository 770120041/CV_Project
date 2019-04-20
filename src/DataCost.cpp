#include "DataCost.h"

//Erase mode for max contrast pixel
double data_cost_contrast(int pixel, int cnt, void *data) {
    ExtraDataContrast *extra_const = (ExtraDataContrast *) data;
    ExtraData *extra_data_pointer = &(extra_const->extra);
    Mat &Label = extra_data_pointer->Label;
    vector<Mat> GaussianBlurImages = extra_const->GaussianImages;
    vector<Mat> &Inputs = extra_data_pointer->Images;

    return -10 * norm(GaussianBlurImages[cnt].at<Vec3b>(pixel / Label.cols, pixel % Label.cols),
                      Inputs[cnt].at<Vec3b>(pixel / Label.cols, pixel % Label.cols));
}


//cal user specify cost
double data_cost_user_specify(int pixel, int cnt, void *extra_data) {
    ExtraData *extra_data_pointer = (ExtraData *) extra_data;
    Mat &Label = extra_data_pointer->Label;
    if (Label.at<char>(pixel / Label.cols, pixel % Label.cols) != LABEL_UNDEFINED) {
        if (Label.at<char>(pixel / Label.cols, pixel % Label.cols) != 0 &&
            Label.at<char>(pixel / Label.cols, pixel % Label.cols) == cnt)
            return 0.0;
        else return BIG_PENALTY;
    } else return BIG_PENALTY;
}

//cal Max Likelihood cost
double data_cost_max_likely(int pixel, int cnt, void *extra_data) {

    ExtraData *extra_data_pointer = (ExtraData *) extra_data;
    Mat &Label = extra_data_pointer->Label;
    vector<Mat> &Inputs = extra_data_pointer->Images;

    const int histo_cnt = 30;
    int histo_rgb[3];

    int user_idx[3];
    float determinant = 255.0 / histo_cnt;
    Mat &user_img = Inputs[cnt];
    for (auto i = 0; i < 3; i++) {
        histo_rgb[i] = 0;
        user_idx[i] = int(floor(user_img.at<Vec3b>(pixel / Label.cols, pixel % Label.cols)[i] / determinant));
    }

    for (auto p: Inputs) {
        for (int i = 0; i < 3; i++) {
            int idx = floor(p.at<Vec3b>(pixel / Label.cols, pixel % Label.cols)[i] / determinant);
            if (idx == user_idx[i]) {
                histo_rgb[i] += 1;
            }
        }
    }

    float bin_avg = (histo_rgb[0] + histo_rgb[1] + histo_rgb[2]) / 3.0;
    if (bin_avg == Inputs.size()) {
        return 0;
    }
    return (1 - bin_avg / Inputs.size()) * BIG_PENALTY;
}

//cal min Likelihooddouble 
double data_cost_min_likely(int pixel, int cnt, void *data) {
    ExtraData *extra_data_pointer = (ExtraData *) data;
    Mat &Label = extra_data_pointer->Label;
    vector<Mat> &Inputs = extra_data_pointer->Images;

    double max_lumin = 0;
    double l_lumin = 0;

    const int histo_cnt = 20;
    int bin_rgb[3];

    int user_idx[3];


    float determinant = 255.0 / histo_cnt;
    const Mat &user_img = Inputs[cnt];
    for (int i = 0; i < 3; i++) {
        bin_rgb[i] = 0;
        user_idx[i] = int(floor(user_img.at<Vec3b>(pixel / Label.cols, pixel % Label.cols)[i] / determinant));
    }

    for (auto p: Inputs) {
        for (int i = 0; i < 3; i++) {
            int idx = floor(p.at<Vec3b>(pixel / Label.cols, pixel % Label.cols)[0] / determinant);
            if (idx == user_idx[i]) {
                bin_rgb[i] += 1;
            }
        }
    }
    float bin_avg = (bin_rgb[0] + bin_rgb[1] + bin_rgb[2]) / 3.0;

    return (bin_avg / Inputs.size()) * BIG_PENALTY;
}

//cal Luminance selection
double data_cost_max_lumin(int pixel, int cnt, void *extra_data) {
    ExtraData *extra_data_pointer = (ExtraData *) extra_data;
    Mat &Label = extra_data_pointer->Label;
    vector<Mat> &Inputs = extra_data_pointer->Images;

    double max_lumin = 0;
    double l_lumin = 0;
    int num_cnt = 0;
    for (auto p: Inputs) {
        // trans fo RUV
        double lumin = 0.299 * p.at<Vec3b>(pixel / Label.cols, pixel % Label.cols)[2] +
                       0.587 * p.at<Vec3b>(pixel / Label.cols, pixel % Label.cols)[1] +
                       0.114 * p.at<Vec3b>(pixel / Label.cols, pixel % Label.cols)[0];
        if (num_cnt++ == cnt) {
            l_lumin = lumin;
        }
        max_lumin = lumin > max_lumin ? lumin : max_lumin;
    }

    return (max_lumin - l_lumin) * 10;
}

//cal Luminance selection
double data_cost_min_lumin(int pixel, int cnt, void *extra_data) {
    ExtraData *extra_data_pointer = (ExtraData *) extra_data;
    Mat &Label = extra_data_pointer->Label;
    vector<Mat> &Inputs = extra_data_pointer->Images;

    double min_lumin = 0;
    double l_lumin = 0;
    int num_cnt = 0;
    // cal YUV
    for (auto p: Inputs) {
        double lumin = 0.299 * p.at<Vec3b>(pixel / Label.cols, pixel % Label.cols)[2] +
                       0.587 * p.at<Vec3b>(pixel / Label.cols, pixel % Label.cols)[1] +
                       0.114 * p.at<Vec3b>(pixel / Label.cols, pixel % Label.cols)[0];
        if (num_cnt++ == cnt) {
            l_lumin = lumin;
        }
        min_lumin = lumin < min_lumin ? lumin : min_lumin;
    }

    return (l_lumin - min_lumin) * 10;
}

//cal erase mode 
double data_cost_erase(int pixel, int cnt, void *extra_data) {
    ExtraData *extra_data_pointer = (ExtraData *) extra_data;
    Mat &Label = extra_data_pointer->Label;
    vector<Mat> &Inputs = extra_data_pointer->Images;

    double max_pixel = 0;
    double l_pixel = 0;
    double penalty = 0;
    double dis, max_dis = 0;
    if (Label.at<char>(pixel / Label.cols, pixel % Label.cols) != LABEL_UNDEFINED) {
        if (Label.at<char>(pixel / Label.cols, pixel % Label.cols) != cnt) return 0.0;
        else return BIG_PENALTY;
    } else return BIG_PENALTY;
}

//cal max diff
double data_cost_max_difference(int pixel, int cnt, void *extra_data) {
    ExtraData *extra_data_pointer = (ExtraData *) extra_data;
    Mat &Label = extra_data_pointer->Label;
    vector<Mat> &Inputs = extra_data_pointer->Images;

    double max_dis = 0;
    double dis;

    for (auto p: Inputs) {
        dis = norm(Inputs.back().at<Vec3b>(pixel / Label.cols, pixel % Label.cols),
                   p.at<Vec3b>(pixel / Label.cols, pixel % Label.cols));
        max_dis = dis > max_dis ? dis : max_dis;
    }
    dis = norm(Inputs.back().at<Vec3b>(pixel / Label.cols, pixel % Label.cols),
               Inputs[cnt].at<Vec3b>(pixel / Label.cols, pixel % Label.cols));
    return (max_dis - dis) * 50;
}

      
      
      
      




