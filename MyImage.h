//
// Created by katharsis on 9/22/22.
//

#ifndef IMAGEPROCESSING_MYIMAGE_H
#define IMAGEPROCESSING_MYIMAGE_H
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include <iostream>


/**
 *@brief Clase que representa una imagen
 */
class MyImage {
    public:
        ///Constructores
        MyImage(std::string fileName);
        MyImage(cv::Mat imageMatrix);


        ///Atributos
        std::string fileName;
        cv::Mat imageMatrix;
        cv::Mat modImageMatrix;

        ///Metodos
        cv::Mat getMatrix(std::string fileName);
        void showBefImage();
        void showAftImage();

};


#endif IMAGEPROCESSING_MYIMAGE_H
