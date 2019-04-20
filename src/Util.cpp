#include "Util.h"

/***************
    This Section includes utils for parse.cpp
*/

// parse user coefficient
float ParseCoefficient(const char* s){
  float rez = 0, fact = 1;
  if (*s == '-'){
    s++;
    fact = -1;
  };
  for (int point_seen = 0; *s; s++){
    if (*s == '.'){
      point_seen = 1; 
      continue;
    };
    int d = *s - '0';
    if (d >= 0 && d <= 9){
      if (point_seen) fact /= 10.0f;
      rez = rez * 10.0f + (float)d;
    };
  };
  return rez * fact;
};


// parse penalty mode
int ParseMode(char *str) 
{ 
    int result = 0; 
    for (int i = 0; str[i] != '\0'; ++i) 
        result = result*10 + str[i] - '0'; 
    return result; 
} 

// Reading mat and resize according to ratio
Mat ReadAndResize(string path,float ratio=1){   
    
    Mat img = imread(path);
    
    if(img.empty()){
        fprintf(stderr,"imgs path %s is invalid\n",path.c_str());
        exit(-1);
    }
    
#ifdef DEBUG
    cout<<"Read and resizeing Image:";
    cout<<path<<" "<<floor(img.cols/ratio)<<","<<floor(img.rows/ratio)<<endl;
#endif

    // resize image to desire size
    Mat result;
    resize(img, result, Size(img.cols/ratio,img.rows/ratio),INTER_AREA);

    return result;
}

// Function to print result for debug
void debug_print(string s){
#ifdef DEBUG
    cout<<s<<endl;
#endif
}



//    Function fo parse Image from argv and argv, also return the result Lable Mat 
Mat parseImageAndLabel(int argc, char* argv[],vector<Mat> &Inputs, bool NeedLabel){
    Mat resultLabel;
    vector<Mat> Labels;

    if(NeedLabel){
        if(argc %2 != 0){
            fprintf(stderr," Mode Need Lable but label and image not match!\n");
            exit(-1);
        }
        int numOfImages = argc/2;
        char logbuffer[2000];
        sprintf(logbuffer,"%d images and labels",argc);
        debug_print(logbuffer);
        
        // there are same number of images and Lables
        
        // Store all input images, resize if necessary
        for(int i=0 ; i < numOfImages ; i++){
            Inputs.push_back(ReadAndResize(argv[i],1));
        }
        // Store all labels
        for(int i=numOfImages ; i < argc ; i++){
            //UNdefined used for auto blending
            if(strcmp(argv[i],"UNDEFINED") == 0){
                Mat tempPlate(Inputs[0].rows, Inputs[0].cols, CV_8SC1);
                tempPlate.setTo(0);
                Labels.push_back(tempPlate);
                debug_print("Label is undefined");
            }
            //PLATE used for erasing
            else if(strcmp(argv[i],"PLATE") == 0){
                Mat tempPlate(Inputs[0].rows, Inputs[0].cols, CV_8SC1);
                tempPlate.setTo(1); 
                Labels.push_back(tempPlate);
                debug_print("Label is plate");
            }
            // User specified labels
            else{
                Labels.push_back(ReadAndResize(argv[i],1));
                debug_print("Label pushed");
            }
        }

        // store all labels to one lable and pass it to Digital Montage functions
        resultLabel = Mat(Inputs[0].rows, Inputs[0].cols, CV_8SC1);
        resultLabel.setTo(LABEL_UNDEFINED);
        for (auto label_idx = 0 ; label_idx < Labels.size(); label_idx++)
        {
            for (int y = 0; y < Inputs[0].rows; y++)
            {
                for (int x = 0 ; x < Inputs[0].cols; x++)
                {
                    if (Labels[label_idx].at<Vec3b>(y,x)(0) > 0
                    || Labels[label_idx].at<Vec3b>(y,x)(1) > 0
                    || Labels[label_idx].at<Vec3b>(y,x)(2) > 0)
                    {
                        resultLabel.at<uchar>(y,x) = int(label_idx);
                    }
                }
            }
        }
    }

    else{
        for(int i=0 ; i < argc ; i++){
            Inputs.push_back(ReadAndResize(argv[i],1));
        }
        resultLabel = Mat(Inputs[0].rows, Inputs[0].cols, CV_8SC1);
        resultLabel.setTo(LABEL_UNDEFINED);
    }

    return resultLabel;

}

/*
    End of utils for parser.cpp
******************/


/***********************************************************
    This Section includes utils for DigitalMontage.cpp
*/

//Function to cal the euc_dist between two vec3b points
double euc_dist(const Vec3b & a, const Vec3b & b)
{
    Vec3b double_diff = a - b;
    return sqrt( double_diff[0] * double_diff[0] + double_diff[1] * double_diff[1] + double_diff[2] * double_diff[2]);
}


 //Define interaction penalty Ci over all pairs of neighboring pixels A and B
 //Seam objective to be 0 if L(A) = L(B). Otherwise, we implement following calculation:
double smoothFn(int point_a, int point_b, int LabelA, int LabelB, void * data)
{
    if (LabelA == LabelB)
    {
        return 0.0;
    }
    if(LabelA == LabelB){
        fprintf(stderr,"label A  equals to Label B\n");
        exit(-1);
    }

    // get extra data of Label and images
    ExtraData* extra_data_ = (ExtraData*)data;
    Mat& Label = extra_data_->Label;
    vector<Mat> &InputsImage = extra_data_->Images;
    int lable_size = InputsImage.size();
    double user_coefficient = extra_data_->user_param;
    int currentMode =  extra_data_->cur_mode;

    if(!(LabelA < lable_size && LabelB < lable_size)){
        fprintf(stderr,"label A  or Label B size differ\n");
        exit(-1);
    }
    
    int width = Label.cols;
    
    // cal culate the term 
    double X_term1 = euc_dist(InputsImage[LabelA].at<Vec3b>(point_a / width,point_a % width),InputsImage[LabelB].at<Vec3b>(point_a / width,point_a % width));
    double X_term2 = euc_dist(InputsImage[LabelA].at<Vec3b>(point_b / width,point_b % width), InputsImage[LabelB].at<Vec3b>(point_b / width,point_b % width));
    if(X_term1 + X_term1 < 0){
        fprintf(stderr,"x_term1+xterm_2 <0 error\n");
        exit(-1);
    }

    // cal gradient at 6 directions
    double gradient_of_a[6];
    double gradient_of_b[6];
    for(int i=0;i<6;i++) gradient_of_a[i]=gradient_of_b[i] = 0;
    calculate_gradient_at_xy(InputsImage[LabelA], point_a % width, point_a / width,gradient_of_a);
    calculate_gradient_at_xy(InputsImage[LabelB], point_a % width, point_a / width,gradient_of_b);
    
    
    double diff_grad=0;
    double diff_grad1=0;
    for(int k=0;k<6;k++){
        diff_grad+=pow(gradient_of_a[k]-gradient_of_b[k],2);
    }
    diff_grad=sqrt(diff_grad);
    
    calculate_gradient_at_xy(InputsImage[LabelA], point_b % width, point_b / width,gradient_of_a);
    calculate_gradient_at_xy(InputsImage[LabelB], point_b % width, point_b / width,gradient_of_b);
    
    for(int k=0;k<6;k++){
        diff_grad1+=pow(gradient_of_a[k]-gradient_of_b[k],2);
    }
  

    diff_grad1=sqrt(diff_grad1);
    int coefficient = 10;
    if(user_coefficient > 0){
        coefficient*=user_coefficient;
    }
    else{
        if(currentMode == USER_SPECIFY || currentMode == USER_SPECIFY_P){
            coefficient*=2;
        }
        else if (currentMode == MAX_LIKEHOOD){
            coefficient *= 5;
        }
        else if(currentMode == ERASE){
            coefficient /=2;
        }
    }

    return ((X_term1 + X_term2) * coefficient + diff_grad * coefficient + diff_grad1 * coefficient);
  
}

//calculates 6D grad with X,Y direction on all channel
void calculate_gradient_at_xy(const Mat & image,int x,int y,double grad[]){
    int flag=0;
    double l,ld,r,rd,ru,lu,u,d;
    l=ld=r=rd=ru=lu=u=d=0;
    for(int i =0;i<image.channels();i++){
        if(x==0){
            l=0;
            ld=0;
            lu=0;
        }
        else if(x==image.cols-1){
            r=0;
            rd=0;
            ru=0;
        }
        else{
            l=image.at<Vec3b>(y, x-1)[i];
            r=image.at<Vec3b>(y, x+1)[i];
            flag=1;
        }
        if (y==0){
            u=0;
            lu=0;
            ru=0;
        }
        else if(y==image.rows-1){
            d=0;
            ld=0;
            rd=0;
        }
        else{
            if(flag==1){
                lu=image.at<Vec3b>(y-1, x-1)[i];
                ld=image.at<Vec3b>(y+1, x-1)[i];
                ru=image.at<Vec3b>(y-1, x+1)[i];
                rd=image.at<Vec3b>(y+1, x+1)[i];
                
            }
            u=image.at<Vec3b>(y-1, x)[i];
            d=image.at<Vec3b>(y+1, x)[i];
            
            
        }
        
        grad[i]=ru+2*r+rd-2*l-ld-lu;
        grad[i+3]=lu+2*u+ru-ld-2*d-rd;
        
    }
    return ;
    
}


void cal_color_gradient( const cv::Mat & Image, int x, int y, cv::Vec3f & grad_x, cv::Vec3f & grad_y )
{
    
    Vec3i color1 = Image.at<Vec3b>(y, x);
    Vec3i color2 = Image.at<Vec3b>(y, x + 1);
    Vec3i color3 = Image.at<Vec3b>(y + 1, x);
    grad_x = color2 - color1;
    grad_y = color3 - color1;
    
}
