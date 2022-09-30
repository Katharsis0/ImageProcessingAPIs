#include <iostream>
//libreria cliente servidor
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
//libreria para el manejo de matrices
#include <opencv4/opencv2/opencv.hpp>
#include <opencv4/opencv2/core.hpp>
#include "MyImage.h"

using namespace std;
//using namespace cv;

//Se compila con g++ -o client client.cpp `pkg-config --cflags --libs opencv4`
//g++ client.cpp -o client -L /us/lib/ -lboost_system -lboost_thread -lpthread
///Global variables
int filtro;
bool active;
bool waitingResponse;
string directorio;


void startApp(){

        cout << "Bienvenido al Programa de Procesamiento de Imágenes" << endl;
        sleep(2);
        active= true;
        cout << "El programa consiste de la aplicación de filtros a una imagen" << endl;
        sleep(2);
        cout << "El programa cuenta con los siguientes filtros:" << endl;
        sleep(2);
        cout << "1. Escala de grises" << endl;
        cout << "2. Desenfoque Gaussiano" << endl;
        cout << "3. Control de brillo" << endl;
        cout << "4. Corrección Gamma" << endl;
        sleep(4);
        cout << "Por favor ingrese el directorio de la imagen que desea procesar" << endl;
        cin >> directorio;
        sleep(2);
        cout << "Por favor ingrese el número de filtro a utilizar" << endl;
        sleep(2);
        cin >> filtro;
        if(filtro==1){
            cout << "El filtro ingresado es: Escala de Grises" << endl;
        }
        if (filtro==2){
            cout << "El filtro ingresado es: Desenfoque Gaussiano" << filtro << endl;
        }
        if (filtro==3){
            cout << "El filtro ingresado es: Control de brillo" << filtro << endl;
        }
        if (filtro==4){
            cout << "El filtro ingresado es: Correcciòn Gamma" << filtro << endl;
        }
};


int main() {

    startApp();
    MyImage originalImage= MyImage(directorio);

    boost::asio::io_service io_service; // Servicio de input/output
    boost::asio::ip::tcp::socket socket(io_service); // Declaracion de socket para conexiones
    boost::system::error_code error; // Variable para codigo de error especifico de Boost
    boost::asio::streambuf receive_buffer; // Buffer para recibir mensajes
    const string outMessage; // Mensaje a enviar
    const string filterCode = boost::lexical_cast<string>(filtro); // Codigo de filtro a enviar
    const string segment= originalImage.matToString(); // Segmento de imagen a enviar


    socket.connect(boost::asio::ip::tcp::endpoint( boost::asio::ip::address::from_string("127.0.0.1"), 1234));// Conecta socket a IP local con puerto del servidor
    cout << "Conectado al servidor" << endl;
    boost::asio::write(socket, boost::asio::buffer(segment), error); // Escribe mensaje al servidor
    if (!error) {
    cout << "Mensaje enviado" << endl;    }
    else {
    cout << "error" << error.message() << endl;
    }
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(),error); // Guarda mensaje recibido en el buffer
    if (error && error != boost::asio::error::eof) {
            cout << "error" << error.message() << endl;
        }
    else {
        const char *inMessage = boost::asio::buffer_cast<const char *>(
                receive_buffer.data()); // Interpreta mensaje recibido
        if (!error) {
            std::string Code = inMessage;
            boost::asio::write(socket, boost::asio::buffer(segment), error); // Escribe segmento al servidor
        };
        boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(),error); // Guarda mensaje recibido en el buffer
    }


        return 0;
}