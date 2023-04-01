#include <iostream>
#include <string>
#include <stdlib.h>

#include "lib/functions.hpp"

using namespace std;

House new_house(){
    House p__house;

    cout << "Ingresa el numero de casa: ";
    getline(cin, p__house.number);
    while (p__house.number == ""){
        cout << "Este campo no puede estar vacio! Intenta de nuevo: ";
        getline(cin, p__house.number);
    }

    cout << "Ingresa el color de la casa: ";
    getline(cin, p__house.color);
    while (p__house.color == ""){
        cout << "Este campo no puede estar vacio! Intenta de nuevo: ";
        getline(cin, p__house.color);
    }

    cout << "Ingresa el numero de personas que residen en la casa: ";
    cin >> p__house.people;

    while (p__house.people < 0){
        cout << "La informacion ingresada no es valida! Intenta de nuevo: ";
        cin >> p__house.people;
    }

    return p__house;
}

void print_house( House house){
    if (house.number == "INVALID_DATA")
    {
        cout << "\n\t\t***ERROR***\nNo se puede imprimir el registro...\n";
        return;
    }
    cout << "\n--------------------------------------------";
    cout << "\nNumero de casa: " << house.number;
    cout << "\nColor: " << house.color;
    cout << "\nPersonas residiendo en la casa: " << house.people;
    cout << "\n--------------------------------------------";
    return;
}

void print_house(string number, HouseNode* list){
    HouseNode* temp_pointer = find_house_node(list, number);
    if (temp_pointer == NULL){
        cout << "\n\t\t***ERROR***\nNo se puede imprimir el registro...\n";
        return;
    }
    print_house(temp_pointer->element);
    return;
}