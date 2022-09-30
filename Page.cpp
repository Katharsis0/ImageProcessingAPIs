//
// Created by katharsis on 9/28/22.
//

#include "Page.h"
/**
 *@brief Constructor de la clase Page
 *@param int content: Contenido de la página
 * @param int pageNumber: número de página
 */
Page::Page(cv::Mat content, int pageNumber) {
    this->content = content;
    this->pageNumber = pageNumber;
}

/**
 *@brief Obtener el contenido de la página
 * @return cv::Mat content: Contenido de la página
 */
cv::Mat Page::getContent() {
    return this->content;
}
/**
 *@brief Establecer el número de la página
 *@param int pageNumber: Número de la página
 */
int Page::setPageNumber(int pageNumber) {
    this->pageNumber = pageNumber;
}
/**
 *@brief Obtener el número de la página
 *@return int pageNumber: Número de la página
 */
int Page::getPageNumber() {
    return this->pageNumber;
}
