#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <regex>
#include "lib/functions.hpp"

const regex email_pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
const regex phone_pattern("\\d{4}-\\d{4}");

Contact CreateContact()
{
    Contact p__contact;

    cout << "Ingresa los nombres del contacto: ";
    getline(cin, p__contact.first_names);
    while (p__contact.first_names == "")
    {
        cout << "Este campo no puede estar vacio! Intenta de nuevo: ";
        getline(cin, p__contact.first_names);
    }

    cout << "Ingresa los apellidos del contacto: ";
    getline(cin, p__contact.last_names);

    cout << "Ingresa el numero de contacto (Formato: 0000-0000): ";
    getline(cin, p__contact.phone_number);
    while (p__contact.phone_number == "" || !regex_match(p__contact.phone_number, phone_pattern))
    {
        if (p__contact.phone_number == "" )
            cout << "Este campo no puede estar vacio! Intenta de nuevo: ";
        else if (!regex_match(p__contact.phone_number, phone_pattern))
            cout << "Formato no valido! Por favor, intenta de nuevo: ";
        getline(cin, p__contact.phone_number);
    }

    cout << "Ingresa el e-mail del contacto: ";
    getline(cin, p__contact.email);
    if (p__contact.email != "")
    {
        while (!regex_match(p__contact.email, email_pattern) && p__contact.email != "")
        {
            cout << "Esa no es una direccion de correo valida. Por favor, intenta de nuevo: ";
            getline(cin, p__contact.email);
        }
    }


    if (p__contact.last_names == "")
        p__contact.last_names = "Sin registros";
    if (p__contact.email == "")
        p__contact.email = "Sin registros";

    return p__contact;
}

Contact GetFirstContact(Node **list)
{
    return (*list)->element;
}

Contact GetLastContact(Node **list)
{
    Node *temp_pointer = new Node();

    temp_pointer = *list;
    while (temp_pointer->next != NULL){
        temp_pointer = temp_pointer->next;
    };

    return (temp_pointer)->element;
}

Contact GetContact(string phone_number, Node **list)
{
    Node *temp_pointer = findNode(list, phone_number);
    if (temp_pointer == NULL)
        return invalidData;
    else
        return (temp_pointer)->element;
}

void PrintContact(Contact contact)
{
    if (contact.first_names == "INVALID_DATA"){
        cout << "\n\t\t***ERROR***\nNo se puede imprimir el registro...\n";
        return;
    }
    cout << "\n--------------------------------------------";
    cout << "\nNombres: " << contact.first_names;
    cout << "\nApellidos: " << contact.last_names;
    cout << "\nNumero de contacto: " << contact.phone_number;
    cout << "\nE-mail: " << contact.email;
    cout << "\n--------------------------------------------";
    return;
}

void PrintContact(string phone_number, Node **list)
{
    Node *temp_pointer = findNode(list, phone_number);
    if (temp_pointer == NULL){
        cout << "\n\t\t***ERROR***\nNo se puede imprimir el registro...\n";
        return;
    }
    PrintContact(temp_pointer->element);
    return;
}