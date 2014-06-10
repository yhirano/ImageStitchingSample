// OpenCV2 Stiching sample

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/stitching/stitcher.hpp>

using namespace std;
using namespace cv;

static const char* FILE_PATH = "/Users/hirano/Desktop/img.png";

int main(int argc, const char * argv[])
{
    if (argc < 3) {
        cout << "Input 2 images at least." << endl;
        return -1;
    }
    
    vector<Mat> imgs;
    
    stringstream errorMessage;
    
    for (int i = 1; i < argc; ++i) {
        Mat img = imread(argv[i]);
        if (img.empty()) {
            errorMessage << "Not found image \"" << argv[i] << "\"." << endl;
        } else {
            imgs.push_back(img);
        }
    }
    
    if (imgs.empty()) {
        cout << "Input 2 images at least." << endl;
        cout << errorMessage.str() << endl;
        return -1;
    }
    
    Mat pano;
    Stitcher stitcher = Stitcher::createDefault();
    Stitcher::Status status = stitcher.stitch(imgs, pano);
    
    if (status != Stitcher::OK)
    {
        cout << "Can't stitch images, error code = " << int(status) << endl;
        return -1;
    }
    
    imwrite(FILE_PATH, pano);
    
    //imshow("Pano", pano);
    
    //waitKey(0);
    
    //destroyWindow("Pano");
    
    return 0;
}

