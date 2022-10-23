// Crear un programa que simule un diccionario que cuente como máximo con 5 palabras por cada letra
//     del alfabeto, que le permita al usuario realizar las siguientes acciones:

//     1.  Agregar palabras, significado, sinónimo, antónimo, entre otros
//     2.  Eliminar una palabra
//     3.  Buscar palabras en específico
#include <iostream>
#include <fstream>
#include "lib/functions.hpp"

using namespace std;

void WriteTimeToFile(string time);
void ReadTimeOfFile();

int main()
{
    string CurrentTime = DateTimeStamp();
    cout << "Hello world!\n" << "This message was sent " << CurrentTime;

    WriteTimeToFile(CurrentTime);
    ReadTimeOfFile();

    return 0;
}


void WriteTimeToFile(string time)
{
    ofstream data_file ("res/data_file.txt", ios::app);
    data_file << time;
    data_file.close();
}
void ReadTimeOfFile()
{
    ifstream data_file ("res/data_file.txt");
    string time,time2,time3,time4,time5;
    while (data_file >> time >> time2 >> time3 >> time4 >> time5)
    {
        cout << time << " " << time2 << " " << time3 << " " << time4 << " " << time5 << " " << "\n";
    }
    
    return;
}