//
// Created by katharsis on 9/28/22.
//

#include "Page.h"

/**
 *@brief Constructor de la clase Page
 *@param int content: Contenido de la página y numero de pagina, int pageNumber: número de página
 */
Page::Page(int content, int pageNumber) {
    this->content = content;
    this->pageNumber = pageNumber;
}
/**
 *@brief Obtener el contenido de la página
 * @return int content: Contenido de la página
 */
int Page::getContent() {
    return this->content;
}
/**
 *@brief Obtener el número de la página
 * @return int pageNumber: Número de la página
 */
int Page::getPageNumber() {
    return this->pageNumber;
}

