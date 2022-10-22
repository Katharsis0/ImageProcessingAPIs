//
// Created by katharsis on 9/28/22.
//

#ifndef IMAGEPROCESSING_PAGEMANAGER_H
#define IMAGEPROCESSING_PAGEMANAGER_H
#include "Page.h"

/**
 *@brief Clase que se encarga de manejar las paginaciones
 */
class PageManager {
    public:
        ///Constructor
        PageManager(Page page, int frameSize);
        ///Atributos
        Page page;
        int const frameSize=2000;
        int frames[7]={-1,-1,-1,-1,-1,-1,-1};


        ///Metodos



};


#endif //IMAGEPROCESSING_PAGEMANAGER_H
