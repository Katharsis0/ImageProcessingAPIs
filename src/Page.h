//
// Created by katharsis on 9/28/22.
//

#ifndef IMAGEPROCESSING_PAGE_H
#define IMAGEPROCESSING_PAGE_H

/**
 *@brief Clase que representa una página
 */
class Page {
    ///Constructor
    Page(int content, int pageNumber);
    ///Atributos
    int content;
    int pageNumber;
    int pageSize=2000;
    ///Metodos
    int getContent();
    int getPageNumber();
};


#endif //IMAGEPROCESSING_PAGE_H
