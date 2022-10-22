//
// Created by dansecan on 30/09/22.
//
#include "../src/Filters.h"
#include "gtest/gtest.h"
#include "../src/MyImage.h"

TEST(grayScaleTest,grayTest){
    MyImage img= MyImage("Images/Haze6.jpg");
    cv::Mat matrix = img.getMatrix();
    Filters filters=Filters(matrix,"image");;
    filters.grayScale();
    filters.gaussianBlur(1,3);
    filters.brigthness(-100);
    filters.gammaCorrection(5,5);
}
int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
