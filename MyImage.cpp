//
// Created by katharsis on 9/22/22.
//
#include "MyImage.h"

/* @brief Constructor de la clase MyImage
 * @param fileName Nombre (o directorio) del archivo de la imagen
*/
MyImage::MyImage(std::string fileName){
    this->imageMatrix = MyImage::getMatrix(fileName);
}

/* @brief Constructor de la clase MyImage
 * @param imageMatrix matriz de una imagen
*/
MyImage::MyImage(cv::Mat imageMatrix){
    this->imageMatrix = imageMatrix;
}

/* @brief Obtiene la matriz de una imagen
 * @param string filename Nombre (o directorio) del archivo de la imagen
*/
cv::Mat MyImage::getMatrix(std::string filename){
    cv::Mat imageMatrix = cv::imread(filename, cv::IMREAD_UNCHANGED);
    return imageMatrix;
}

/* @brief Despliega la imagen
 * @param imageMatrix matriz de una imagen
*/
void MyImage::showBefImage(){
    cv::imshow("Imagen original", imageMatrix);
    cv::waitKey(0);
    }

/* @brief Despliega la imagen
 * @param imageMatrix matriz de una imagen
*/
void MyImage::showAftImage() {
    cv::imshow("Imagen modificada", modImageMatrix);
    cv::waitKey(0);
}


