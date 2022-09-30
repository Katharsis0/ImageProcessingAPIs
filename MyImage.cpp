//
// Created by katharsis on 9/22/22.
//
#include "MyImage.h"
#include "Page.h"
#include "PageManager.h"

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
    ///En esta matriz de datos, todos los valores de píxeles se almacenan en una matriz de 1D. (b1, g1, r1, b2, g2, r2, ...) .
    /// Las imágenes en OpenCV siempre se almacenan en el formato de BGR.
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
    cv::imshow("Imagen modificada", imageMatrix);
    cv::waitKey(0);
}
/**
 *@brief Obtener el número de columnas de una imagen
 * @return int cols: número de columnas
 */
cv::Mat MyImage::getRowI(int i) {
    cv::Mat rowI= this->imageMatrix.row(i);
    std::cout << rowI << std::endl;
    return rowI;
}
/**
 *@brief Obtener el número de filas de una imagen
 * @return int rows: número de filas
 */
int MyImage::getRows() {
    return this->imageMatrix.rows;
}
/**
 *@brief Obtener el número de canales de una imagen
 * @return int channels: número de canales
 */
int MyImage::getChannels() {
    int channels= imageMatrix.channels();
    return channels;
}
/**
 *@brief Convertir la matriz a un vector y de vector a string
 *
 *@return string: string de los valores del segmento
 */
std::string MyImage::matToString() {
        ///Aplanar la matriz
    uint totalElements= imageMatrix.total() * imageMatrix.channels();
    cv::Mat flatMatrix= imageMatrix.reshape(1, totalElements);
    uchar* ptr= flatMatrix.data;
    ///Convertir a vector
    std::vector<uchar> vec(flatMatrix.data, flatMatrix.data + flatMatrix.total());
    ///Convertir a string
    std::stringstream ss;
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<uchar>(ss, ""));
    std::string code= ss.str();

    return code;
}

/**
 *@brief Restaura la matriz a partir de un vector generado por un string.
 *
 *@param string str: string de los valores del segmento
 *@return Mat: matriz de los valores del segmento
 */
void MyImage::restoreMat(std::string code) {
    ///Convertir string a vector
    std::stringstream ss(code);
    std::vector<uchar> vec((std::istream_iterator<uchar>(ss)),std::istream_iterator<uchar>());
    ///Convertir a matriz
    cv::Mat restoredMat= cv::Mat(imageMatrix.rows, imageMatrix.cols, imageMatrix.type(), vec.data());
    ///Comprobar que la matriz se haya restaurado correctamente
    cv::imshow("reconstructed", restoredMat);
    cv::waitKey(0);
    }
