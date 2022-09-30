//
// Created by katharsis on 9/22/22.
//

#ifndef IMAGEPROCESSING_MYIMAGE_H
#define IMAGEPROCESSING_MYIMAGE_H
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstddef>
#include <bitset>


/**
 *@brief Clase que representa una imagen
 */
class MyImage {
    public:
        ///Constructores
        MyImage(std::string directorio);
        MyImage(cv::Mat imageMatrix);
        ///Atributos
        std::string fileName;
        cv::Mat imageMatrix;
        cv::Mat modImageMatrix;
        ///Metodos
        cv::Mat setMatrix(std::string filename);
        cv::Mat getMatrix();
        void showBefImage();
        void showAftImage();
        cv::Mat getRowI(int i);
        int getRows();
        int getChannels();
        std::string matToString();
        void restoreMat(std::string);


};

#endif IMAGEPROCESSING_MYIMAGE_H
