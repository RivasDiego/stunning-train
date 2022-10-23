// Crear un programa que simule un diccionario que cuente como máximo con 5 palabras por cada letra
//     del alfabeto, que le permita al usuario realizar las siguientes acciones:

//     1.  Agregar palabras, significado, sinónimo, antónimo, entre otros
//     2.  Eliminar una palabra
//     3.  Buscar palabras en específico
#include <iostream>
#include "lib/functions.hpp"



using namespace std;

int main()
{
    string CurrentTime = DateTimeStamp();
    cout << "Hello world!\n" << "This message was sent " << CurrentTime;
    return 0;
}

