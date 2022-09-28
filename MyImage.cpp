//
// Created by katharsis on 9/22/22.
//
#include "MyImage.h"

/**
 * @brief Constructor de la clase MyImage
 * @param string fileName: Nombre (o directorio) del archivo de la imagen
**/
MyImage::MyImage(std::string fileName){
    this->imageMatrix = MyImage::setMatrix(fileName);
}

/** @brief Constructor de la clase MyImage
 * @param Mat imageMatrix: matriz de una imagen
*/
MyImage::MyImage(cv::Mat imageMatrix){
    this->imageMatrix = imageMatrix;
}

/** @brief Establecer la matriz de una imagen
 * @param string filename: Nombre (directorio) del archivo de la imagen
 * @return Matriz de la imagen
*/
cv::Mat MyImage::setMatrix(std::string filename){
    cv::Mat imageMatrix = cv::imread(filename, cv::IMREAD_UNCHANGED);
    return imageMatrix;
}

/** @brief Obtener la matriz de una imagen
 * @return imageMatrix: Arreglo Matricial
 * */
cv::Mat MyImage::getMatrix(){
    return this->imageMatrix;
}
/** @brief Desplegar la imagen original
 *
*/
void MyImage::showBefImage(){
    cv::imshow("Imagen original", imageMatrix);
    cv::waitKey(0);
    }
/** @brief Desplegar la imagen modificada
 *
*/
void MyImage::showAftImage() {
    cv::imshow("Imagen modificada", modImageMatrix);
    cv::waitKey(0);
}
/**
 *@brief Obtener el número de columnas de una imagen
 * @return int cols: número de columnas
 */
int MyImage::getColumns() {
    int cols= imageMatrix.cols;
    return cols;
}
/**
 *@brief Obtener el número de filas de una imagen
 * @return int rows: número de filas
 */
int MyImage::getRows() {
    int rows= imageMatrix.rows;
    return rows;
}
/**
 *@brief Obtener el número de canales de una imagen
 * @return int channels: número de canales
 */
int MyImage::getChannels() {
    int channels= imageMatrix.channels();
    return channels;
}




