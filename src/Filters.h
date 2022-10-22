//
// Created by dansecan on 29/09/22.
//

#ifndef IMAGEPROCESSINGAPIS_FILTERS_H
#define IMAGEPROCESSINGAPIS_FILTERS_H

#include <opencv2/core/mat.hpp>
using namespace cv;
using namespace std;
class Filters{
public:
    string imgOgName;
    cv::Mat imageMatrix;
    cv::Mat reColorMat;
    Filters(cv::Mat imgMatrix,string name);
    void grayScale();
    void mat2image(Mat editedMatrix, string imgName);
    void gaussianBlur(int val1, int val2);
    void brigthness(int val);
    void gammaCorrection(float alpha, float beta);


};


#endif //IMAGEPROCESSINGAPIS_FILTERS_H
