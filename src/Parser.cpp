
#include "DigitalMontage.h"
#include "Util.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    char logbuffer[1024];

    /*
        Section:
            Read images, params and Labels
    */
    // how many params before images and labels
    const int params_offset = 3;

    if(argc <= params_offset){
        fprintf(stderr,"Argument Error, usage:\n");
        fprintf(stderr,"./project_cml coefficient penalty_mode images\n");
        exit(0);
    }
    

    // Store  images and labels
    vector<Mat> Inputs;
    vector<Mat> Labels;
    // parse user parameters and penalty mode
    int user_param = ParseCoefficient(argv[1]);
    int penalty_mode = ParseMode(argv[2]);
    // store all labels to one lable and pass it to Digital Montage functions
    // if mode don't need labels, then set to 
    Mat resultLabel;

    ///if this mode don't need a label, set all label to undefined
    if(penalty_mode != USER_SPECIFY && penalty_mode != ERASE && penalty_mode != USER_SPECIFY_P  ){
        resultLabel = parseImageAndLabel(argc-params_offset, argv+params_offset, Inputs,false);
    }
    else{
        resultLabel = parseImageAndLabel(argc-params_offset, argv+params_offset, Inputs, true);
    }
    sprintf(logbuffer,"input size %lu\n",Inputs.size());
    debug_print(logbuffer);
    /*
        End Section
    */
    
    /*
        Section:
            Running DigitalMontage and print time
    */
    DigitalMontage digital_montage;
    time_t start = time(NULL);
    digital_montage.Run(Inputs,resultLabel,penalty_mode );
    time_t end = time(NULL);

    sprintf(logbuffer,"Time: %d s\n", int(end-start));
    debug_print(logbuffer);
    // FILE * fp = fopen("finish.txt","w+");
    fprintf(stdout, "Time: %d s\n", int(end-start));
    /*
        End Section
    */

    return 0;
}

