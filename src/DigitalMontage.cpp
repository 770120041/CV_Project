
#include "DigitalMontage.h"
#include "DataCost.h"

char logbuffer[1024];


void DigitalMontage::Run(const std::vector<cv::Mat> &Images, const cv::Mat &Label, int mode, double user_param) {

    if (Images[0].rows != Label.rows || Images[0].cols != Label.cols) {
        fprintf(stderr, " Label and Image Size not Match!\n");
        exit(1);
    }

    currentMode = mode;
    sprintf(logbuffer, "mode is %d", mode);
    debug_print(logbuffer);

// void test_orientation(const char* fname) {
// 	auto mat = read_img(fname);
// 	ScaleSpace ss(mat, NUM_OCTAVE, NUM_SCALE);
// 	DOGSpace dog(ss);
// 	ExtremaDetector ex(dog);
// 	auto extrema = ex.get_extrema();
// 	OrientationAssign ort(dog, ss, extrema);
// 	auto oriented_keypoint = ort.work();

// 	PlaneDrawer pld(mat);
// 	pld.set_rand_color();

// 	cout << "FeaturePoint size: " << oriented_keypoint.size() << endl;
// 	for (auto &i : oriented_keypoint)
// 		pld.arrow(Coor(i.real_coor.x * mat.width(), i.real_coor.y * mat.height()), i.dir, LABEL_LEN);
// 	write_rgb(IMGFILE(orientation), mat);
// }

    // Solve(Images, Label, mode, user_param);
    int image_size = Images.size();
    int label_number = image_size;
    ExtraData extra_data;

    extra_data.Images.resize(image_size);
    for (int i = 0; i < image_size; i++) {
        extra_data.Images[i] = Images[i];
    }
    extra_data.Label = Label;
    extra_data.cur_mode = mode;
    extra_data.user_param = user_param;

    // all shall be of same shape
    int width = Label.cols;
    int height = Label.rows;
    
    try {
        /**
 * Class that implements a simple rectangular matrix stored in a memory buffer and
 * provides convenient matrix-like access using the [] operators.
 *
 * This class has the same memory structure as the un-templated class flann::Matrix_ and
 * it's directly convertible from it.
 */
        SaveResultLabel(Label, label_number);

        GCoptimizationGridGraph *graph_cutter = new GCoptimizationGridGraph(width, height, image_size);
        ExtraDataContrast extra_contrast;
        Vector<Mat> GaussianBlurImages;

        switch (mode) {
            case USER_SPECIFY:
            // Mat32f pic2 = read_img(f2);
// 	imagelist.push_back(pic1);
// 	imagelist.push_back(pic2);

// 	unique_ptr<FeatureDetector> detector;
// 	detector.reset(new SIFTDetector);
// 	vector<Descriptor> feat1 = detector->detect_feature(pic1),
// 										 feat2 = detector->detect_feature(pic2);
// 	print_debug("Feature: %lu, %lu\n", feat1.size(), feat2.size());

// 	Mat32f concatenated = hconcat(imagelist);
// 	PlaneDrawer pld(concatenated);
                debug_print("using user_specify penalty");
                graph_cutter->setDataCost(&data_cost_user_specify, &extra_data);
                break;
            case MAX_LUMIN:
                debug_print("using max_lumin penalty");
                graph_cutter->setDataCost(&data_cost_max_lumin, &extra_data);
                break;
            case MIN_LUMIN:
                debug_print("using min lumin penalty");
                graph_cutter->setDataCost(&data_cost_min_lumin, &extra_data);
                break;
            case ERASE:
                debug_print("using erase penalty");
                graph_cutter->setDataCost(&data_cost_erase, &extra_data);
                break;
            case MAX_LIKEHOOD:
                debug_print("using max_likely penalty");
                graph_cutter->setDataCost(&data_cost_max_likely, &extra_data);
                break;
            case MIN_LIKEHOOD:
                debug_print("using min likely penalty");
                graph_cutter->setDataCost(&data_cost_min_likely, &extra_data);
                break;
            case CONTRAST:
                debug_print("using contrast penalty");
                for (int i = 0; i < Images.size(); i++) {
                    Mat tmp;
                    GaussianBlur(Images[i], tmp, Size(3, 3), 0);
                    extra_contrast.GaussianImages.push_back(tmp);
                }
                extra_contrast.extra = extra_data;
                graph_cutter->setDataCost(&data_cost_contrast, &extra_contrast);
                break;
            case MAX_DIFF:
                debug_print("using max diff penalty");
                graph_cutter->setDataCost(&data_cost_max_difference, &extra_data);
                break;
            case USER_SPECIFY_P:
                graph_cutter->setDataCost(&data_cost_user_specify, &extra_data);
                break;

            default:
                break;
        }

        graph_cutter->setSmoothCost(&smoothFn, &extra_data);
        graph_cutter->swap(10);
        Mat result_label(height, width, CV_8UC1);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int idx = y * width + x;
                result_label.at<uchar>(y, x) = graph_cutter->whatLabel(idx);
            }
        }
        // t.get_transform(&info);
// 	print_debug("Inlier size: %lu, conf=%lf\n", info.match.size(), info.confidence);
// 	if (info.match.size() == 0)
// 		return;

// 	for (auto &x : info.match) {
// 		pld.set_rand_color();
// 		Vec2D coor1 = x.first,
// 					coor2 = x.second;
// 		Coor icoor1 = Coor(coor1.x + pic1.width()/2, coor1.y + pic1.height()/2);
// 		Coor icoor2 = Coor(coor2.x + pic2.width()/2, coor2.y + pic2.height()/2);
// 		pld.circle(icoor1, LABEL_LEN);
// 		pld.circle(icoor2 + Coor(pic1.wi
        delete graph_cutter;
        //Save result label to file for visulization
        SaveResultLabel(result_label, label_number);
        // if current mode need gradient domain fusion to make more seamless
        if (currentMode == USER_SPECIFY_P || currentMode == MAX_DIFF || currentMode == CONTRAST) {
            calGradientDomainFusion(Images, result_label);
        } else {
            SaveCompositeImage(result_label, Images);
        }
    }
    catch (GCException e) {
        e.Report();
    }
}



void DigitalMontage::calGradientDomainFusion(const vector<Mat> &Images, const Mat &ResultLabel) {

    int width = ResultLabel.cols;
    int height = ResultLabel.rows;
    Mat color_result(height, width, CV_8UC3);
    Mat gradientAtX(height, width, CV_32FC3);
    Mat gradientAtY(height, width, CV_32FC3);

    for (int y = 0; y < height - 1; y++) {
        for (int x = 0; x < width - 1; x++) {
            cal_color_gradient(Images[ResultLabel.at<uchar>(y, x)], x, y, gradientAtX.at<Vec3f>(y, x),
                               gradientAtY.at<Vec3f>(y, x));
        }
    }
    Vec3b color0 = Images[0].at<Vec3b>(0, 0);


    struct thread_param para1{1, 0, color0[0], gradientAtX, gradientAtY, color_result};
    struct thread_param para2{2, 1, color0[1], gradientAtX, gradientAtY, color_result};
    struct thread_param para3{3, 2, color0[2], gradientAtX, gradientAtY, color_result};

    pthread_t pid1, pid2, pid3;
    pthread_create(&pid1, NULL, thread_function, &para1);
    pthread_create(&pid2, NULL, thread_function, &para2);
    pthread_create(&pid3, NULL, thread_function, &para3);
/**
 * an entire pool of storage is freed at once.
 * This method has two advantages over just using malloc() and free().  First,
 * it is far more efficient for allocating small objects, as there is
 * no overhead for remembering all the information needed to free each
 * object or consolidating fragmented memory.  Second, the decision about
 * how long to keep an object is made at the time of allocation, and there
 * is no need to track down all the objects to free them.
 *
 */
    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    pthread_join(pid3, NULL);
    imwrite("compositeimage.png", color_result);
}

// solve euqation for one channel
void DigitalMontage::SolveForOneThread(int channel_idx, int constraint, const cv::Mat &gradientAtX,
                                       const cv::Mat &gradientAtY, cv::Mat &output) {
    int UnknowTermNum = 2 * gradientAtX.cols * gradientAtX.rows + 1;
    vector<Eigen::Triplet<double> > Non_tero_term;
    Eigen::VectorXd b(UnknowTermNum);

    // Mat32f pic1 = read_img(f1);
// 	Mat32f pic2 = read_img(f2);
// 	imagelist.push_back(pic1);
// 	imagelist.push_back(pic2);

// 	unique_ptr<FeatureDetector> detector;
// 	detector.reset(new SIFTDetector);
// 	vector<Descriptor> feat1 = detector->detect_feature(pic1),
// 										 feat2 = detector->detect_feature(pic2);
// 	vector<Vec2D> kp1; for (auto& d : feat1) kp1.emplace_back(d.coor);
// 	vector<Vec2D> kp2; for (auto& d : feat2) kp2.emplace_back(d.coor);
// 	print_debug("Feature: %lu, %lu\n", feat1.size(), feat2.size());

// 	Mat32f concatenated = hconcat(imagelist);
// 	PlaneDrawer pld(concatenated);
// 	FeatureMatcher match(feat1, feat2);
    for (int y = 0; y < gradientAtX.rows - 1; y++) {
        for (int x = 0; x < gradientAtX.cols - 1; x++) {
            int index_of_knows = y * gradientAtX.cols + x;
            Non_tero_term.push_back(Eigen::Triplet<double>(2 * index_of_knows, index_of_knows, -1));
            Non_tero_term.push_back(Eigen::Triplet<double>(2 * index_of_knows, y * gradientAtX.cols + (x + 1), 1));
            Vec3f grads_x = gradientAtX.at<Vec3f>(y, x);
            b(2 * index_of_knows) = grads_x[channel_idx];
            Non_tero_term.push_back(Eigen::Triplet<double>(2 * index_of_knows + 1, index_of_knows, -1));
            Non_tero_term.push_back(Eigen::Triplet<double>(2 * index_of_knows + 1, (y + 1) * gradientAtX.cols + x, 1));
            Vec3f grads_y = gradientAtY.at<Vec3f>(y, x);
            b(2 * index_of_knows + 1) = grads_y[channel_idx];
        }
    }

    /* We maintain memory alignment to word boundaries by requiring that all
        allocations be in multiples of the machine wordsize.  */
    /* Size of machine word in bytes.  Must be power of 2. */
    /* Minimum number of bytes requested at a time from	the system.  Must be multiple of WORDSIZE. */
    int eq_idx = gradientAtX.cols * gradientAtX.rows * 2;
    Non_tero_term.push_back(Eigen::Triplet<double>(eq_idx, 0, 1));
    b(eq_idx) = constraint;

    Eigen::SparseMatrix<double> A(UnknowTermNum, gradientAtX.cols * gradientAtX.rows);
    A.setFromTriplets(Non_tero_term.begin(), Non_tero_term.end());
    Non_tero_term.erase(Non_tero_term.begin(), Non_tero_term.end());

    Eigen::SparseMatrix<double> ATA(gradientAtX.cols * gradientAtX.rows, gradientAtX.cols * gradientAtX.rows);
    ATA = A.transpose() * A;
    Eigen::VectorXd ATb = A.transpose() * b;


    Eigen::ConjugateGradient<Eigen::SparseMatrix<double> > newSolver(ATA);
    Eigen::VectorXd result = newSolver.solve(ATb);

    debug_print("Possion equation solveds!\n");

    for (int y = 0; y < gradientAtX.rows; y++) {
        for (int x = 0; x < gradientAtX.cols; x++) {

            Vec3b &temp = output.at<Vec3b>(y, x);
            temp[channel_idx] = uchar(max(min(result(y * gradientAtX.cols + x), 255.0), 0.0));
        }
    }

}
