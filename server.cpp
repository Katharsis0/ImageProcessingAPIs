//
// Created by katharsis on 9/16/22.
//
#include <iostream>
#include <boost/asio.hpp> // Incluir libreria de Boost Asio
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include "MyImage.h"
#include "Filters.h"

using namespace cv;
using namespace std;

std::string completeString;
std::string filter;
cv::Mat modImageMatrix;
cv::Mat imageMatrix;

cv::Mat restoreMessage(std::string code){
       ///Convertir string a vector
        std::stringstream ss(code);
        std::vector<uchar> vec((std::istream_iterator<uchar>(ss)),std::istream_iterator<uchar>());
        ///Convertir a matriz
        cv::Mat restoredMat= cv::Mat(imageMatrix.rows, imageMatrix.cols, imageMatrix.type(), vec.data());
        return restoredMat;
}

/**
 *
 * Funcion que lee mensaje enviado por cliente
 *
 * @param socket
 * @return
 */
string ReadMessage(boost::asio::ip::tcp::socket & socket) {
    boost::asio::streambuf buf; // Buffer de entrada de mensajes
    boost::asio::read_until( socket, buf, ";" ); //  Indica que lea mensaje del socket desde el buffer hasta el delimitador \n
    string data = boost::asio::buffer_cast<const char*>(buf.data()); // Hace cast del buffer de entrada a un char pointer (caracteres legibles)
    return data; // Retorna el mensaje recibido
}
/**
 *
 * Funcion que envia mensaje al cliente
 *
 * @param socket
 * @param message
 */
void SendMessage(boost::asio::ip::tcp::socket & socket, const string& message) {
    const string msg = message + ";"; // Declara variable string con un delimitador linea siguiente
    boost::asio::write( socket, boost::asio::buffer(completeString)); // Envia mensaje a cliente mediante buffer
}


void saveMessage(const string& message){
    ofstream file;
    file.open("message.txt");
    file << message;
    file.close();
}

int main() {
    boost::asio::io_service io_service; // Servicio de input/output
    boost::asio::ip::tcp::acceptor acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 1234));
    // Acepta de manera asincrona conexiones en puerto 1234
    boost::asio::ip::tcp::socket socket_(io_service); // Declaracion de socket para conexiones

    cout << "Servidor iniciado" << endl;

    acceptor_.accept(socket_); // Acepta al socket del cliente que pida conectarse

    cout << "Cliente conectado" << endl;

    completeString = ReadMessage(socket_); // Lee mensaje enviado por cliente
    SendMessage(socket_, "Segmentos recibidos"); // Envia mensaje al cliente
    imageMatrix = restoreMessage(completeString);
    filter= ReadMessage(socket_); // Lee mensaje enviado por cliente
    SendMessage(socket_, "Filtro recibido"); // Envia mensaje al cliente
    //Escala de grises
    if(filter == "1"){
        Filters filter(imageMatrix,"Grey Scale");
        filter.grayScale();
    }
    //Gaussian
    else if(filter == "2"){
        Filters filter(imageMatrix,"Gaussian Blur");
        filter.gaussianBlur( 15, 15);
    }
    //brillo
    else if(filter == "3"){
        Filters filter(imageMatrix,"Brightness Control");
        filter.brigthness( 15);
    }
    //gamma
    else if(filter == "4"){
        Filters filter(imageMatrix,"Gamma Correction");
        filter.gammaCorrection(10,15);
    }

    string message = ReadMessage(socket_); // Lee y declara mensaje del cliente
    completeString= message;


//    cout << "Cliente dice: " + message << endl;

    SendMessage(socket_, "Hola, soy el servidor"); // Envia mensaje al cliente
//    cout << "Mensaje enviado" << endl;
    return 0;
}