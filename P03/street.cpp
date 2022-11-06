#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

#include "lib/functions.hpp"

using namespace std;

Street new_street()
{
    Street p__street;
    char _private;
    bool valid_input = false;

    srand(time(NULL));
    p__street.ID = rand() % 1000 + 1;

    cin.ignore();
    cout << "Ingrese el nombre de la calle: ";
    getline(cin, p__street.name);
    while (p__street.name == "")
    {
        cout << "Este campo no puede estar vacio! Intenta de nuevo: ";
        getline(cin, p__street.name);
    }

    cout << "La calle es privada? (S)i (N)o\t";
    while (!valid_input)
    {
        cin >> _private;
        switch (_private)
        {
        case 'S':
        case 's':
            p__street.is_private = true;
            valid_input = true;
            break;
        case 'N':
        case 'n':
            p__street.is_private = false;
            valid_input = true;
            break;
        default:
            cout << "La opcion ingresada no es valida! Por favor, intente de nuevo:\t";
            valid_input = false;
            break;
        }
    }

    return p__street;
}

void print_street(Street data)
{
    if (data.name == "INVALID_DATA")
    {
        cout << "\n\t\t***ERROR***\nNo se puede imprimir el registro...\n";
        return;
    }
    cout << "\n--------------------------------------------";
    cout << "\nNombre: " << data.name;
    cout << "\nID: " << data.ID;
    cout << "\nEs privada: " << (data.is_private ? "Si" : "No");
    // cout << "\nNumero de casas: " << list_size(data.hosues);
    cout << "\n--------------------------------------------";
    return;
}
void print_street(int ID, Node *tree) {}