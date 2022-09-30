//
// Created by katharsis on 9/30/22.
//

#ifndef IMAGEPROCESSING_FILTERS_H
#define IMAGEPROCESSING_FILTERS_H

#include <opencv2/core/mat.hpp>
using namespace cv;
using namespace std;
class Filters{
public:
    Filters(cv::Mat imgMatrix,string name);
    string imgOgName;
    cv::Mat imageMatrix;
    cv::Mat reColorMat;
    void grayScale();
    void mat2image(Mat editedMatrix, string imgName);
    void gaussianBlur(int val1, int val2);
    void brigthness(int val);
    void gammaCorrection(float alpha, float beta);


};

#endif //IMAGEPROCESSING_FILTERS_H
