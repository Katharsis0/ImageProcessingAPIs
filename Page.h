//
// Created by katharsis on 9/28/22.
//

#ifndef IMAGEPROCESSING_PAGE_H
#define IMAGEPROCESSING_PAGE_H
#include <opencv4/opencv2/opencv.hpp>

///Tamaño del frame (bytes)
const int FRAMESZE=2000;
///Cantidad de frames
const int FRAMEQTY=7;
///Arreglo de frames (contiene el indice de cada página cargada)
int frames[FRAMEQTY]={-1,-1,-1,-1,-1,-1,-1};
///Tamaño de la pagina (bytes)
const int PGSZE=FRAMESZE;
///Puntero a un arreglo que contiene las páginas cargadas
int* pageContainer[FRAMEQTY];
/**
 *@brief Clase que representa una página
 */
class Page {
    public:
        ///Constructor
        Page(cv::Mat content, int pageNumber);

        cv::Mat content;
        int pageNumber;
        ///Metodos
        cv::Mat getContent();
        int setPageNumber(int pageNumber);
        int getPageNumber();
        int getPageSize();
};


#endif IMAGEPROCESSING_PAGE_H










