
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include "Filters.h"


void Filters::grayScale() {
    Mat editedMatrix=reColorMat;
    cvtColor(imageMatrix, editedMatrix, COLOR_BGR2GRAY);
    reColorMat=editedMatrix;
    mat2image(reColorMat,"gray"+imgOgName);
}
void Filters::gaussianBlur(int val1, int val2){
    Mat editedMatrix=reColorMat;
    GaussianBlur(imageMatrix,editedMatrix,Size(val1, val2),0);
    mat2image(editedMatrix,"gaussian"+imgOgName);
}
void Filters::brigthness(int val){
    Mat originalMatrix=imageMatrix;
    Mat editedMatrix=reColorMat;
    originalMatrix.convertTo(editedMatrix, -1,1,val);
    reColorMat=editedMatrix;
    mat2image(editedMatrix,"lightChange"+imgOgName);

}
void Filters::gammaCorrection(float alpha, float beta){
    Mat rgbMat;
    cvtColor(imageMatrix,rgbMat,COLOR_BGR2RGB);
    Mat newMat = Mat::zeros(imageMatrix.size(),imageMatrix.type());
    double alphaVal=alpha;
    int betaVal=beta;

    for(int i =0; i<imageMatrix.rows;i++){
        for(int j=0; j<imageMatrix.cols;j++){
            for(int z=0;z<imageMatrix.channels();z++){
                newMat.at<Vec3b>(i,j)[z]=saturate_cast<uchar>(alphaVal*imageMatrix.at<Vec3b>(i,j)[z]+betaVal);

            }
        }
    }
    reColorMat=newMat;
    mat2image(reColorMat, "gamma"+imgOgName);
}
void Filters::mat2image(Mat editedMatrix,string imgName){
    cv::imwrite("Images/"+imgName+".jpg",editedMatrix);

}
Filters::Filters(cv::Mat imgMatrix, string name) {
    imageMatrix=imgMatrix;
    imgOgName=name;
}