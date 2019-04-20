#ifndef DIGITALMONTAGE_CONSTANTS
#define DIGITALMONTAGE_CONSTANTS

// In total 9 modes of Data Penaly for our program

/*  
    Mode Usage:
        Different modes are actually different ways of calculate  penalty for point p
        , and the distance is calculated relatively to the image objective.
    
    Mode Introduction:
        0.User_Specify:  for user defined stroke, need label painted by user
            P(penalty)P = 0 if L(p) = user stroke, otherwise P=Large penalty 
            The result would be a blending of images where the painted area would be most likely used 
            for the composite image

        1.Maximum luminance: don't need label, auto blending of image
            Distance in luminance from the maximum luminance
            pixel in a range of pixels. The result would be a maximum luminance
            of the sets of image

        2.Minimum luminance: don't need label, auto blending of image
            Similiar to Maximum luminance, but the distance would be the minimum
            luminance pixel

        3.Erase: for user defined stroke, need label painted by user and need plate image as background
            The result would be a blending of images where the painted area would be erased
            for the composite image

        4.Minimum (maximum) likelihood

        6.Contrase, also known as Maximum difference:
            Would select areas where differs most. The composite image would span the
            depth of image.
        
 

*/


enum Mode {
    USER_SPECIFY,
    MAX_LUMIN,
    MIN_LUMIN,
    ERASE,
    MAX_LIKEHOOD,
    MIN_LIKEHOOD,
    CONTRAST,
    MAX_DIFF,
    USER_SPECIFY_P
};


// used for special labels(auto-blending)
enum {
    LABEL_UNDEFINED = -1,
    LABEL_PLATE = 1,
};

// big penalty for different modes, can be adjusted by users
const double BIG_PENALTY = 1000.0;

#endif