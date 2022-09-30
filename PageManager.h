//
// Created by katharsis on 9/28/22.
//

#ifndef IMAGEPROCESSING_PAGEMANAGER_H
#define IMAGEPROCESSING_PAGEMANAGER_H
#include "Page.h"
#include "MyImage.h"

/**
 *@brief Clase que se encarga de manejar la segmentaci
 */
class PageManager {
    public:
        ///Constructor
        PageManager(std::string fileName);
        ///Atributos
        bool miss;
        bool hit;
        ///Metodos
        void FIFO();





};




#endif //IMAGEPROCESSING_PAGEMANAGER_H
