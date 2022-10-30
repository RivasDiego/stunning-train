#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "lib/functions.hpp"

using namespace std;

void Welcome();
void RemoveElements(Node **list);
void AddElements(Node **list);
void ShowElements(Node **list);
bool Exit(Node **list);

int main()
{
    Node *dictionary = ReadFiles();
    int menu_option = 0;
    bool is_saved = false, show_menu = true;

    Welcome();

    do
    {
        cout << "\nMENU PRINCIPAL\n";
        cout << "\t1 - Agregar elementos\n";
        cout << "\t2 - Eliminar elementos\n";
        cout << "\t3 - Mostrar registros actuales\n";
        cout << "\t4 - Salir\n";
        cout << "\nPor favor, ingrese una opcion: ";
        cin >> menu_option;
        switch (menu_option)
        {
        case 1:
            AddElements(&dictionary);
            show_menu = true;
            break;
        case 2:
            RemoveElements(&dictionary);
            show_menu = true;
            break;
        case 3:
            ShowElements(&dictionary);
            show_menu = true;
            break;
        case 4:

            show_menu = Exit(&dictionary);
            break;

        default:
            cout << "La opcion ingresada no es valida. Por favor, intentar de nuevo\n\n";
            show_menu = true;
            break;
        }
    } while (show_menu == true);

    return 0;
}

void AddElements(Node **list)
{
    int menu_option;
    bool show_menu = true;
    string ui_word;
    do
    {
        cout << "\n---- Agregar elementos -----\n";
        cout << "\t1 - Agregar al principio\n";
        cout << "\t2 - Agregar al final\n";
        cout << "\t3 - Agregar antes de alguna palabra\n";
        cout << "\t4 - Agregar despues de alguna palabra\n";
        cout << "\t5 - Salir\n";
        cout << "Por favor, ingrese una opcion: ";
        cin >> menu_option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (menu_option)
        {
        case 1:
            AddAtStart(CreateWord(), list);
            show_menu = true;
            break;
        case 2:
            AddAtEnd(CreateWord(), list);
            show_menu = true;
            break;
        case 3:
            cout << "Ingresa la palabra: ";
            cin >> ui_word;
            AddBefore(CreateWord(), list, ui_word);
            ui_word = "";
            show_menu = true;
            break;
        case 4:
            cout << "Ingresa la palabra: ";
            cin >> ui_word;
            AddAfter(CreateWord(), list, ui_word);
            ui_word = "";
            show_menu = true;
            break;
        case 5:
            show_menu = false;
            break;

        default:
            cout << "La opcion ingresada no es valida. Por favor, intentar de nuevo\n\n";
            show_menu = true;
            break;
        }
    } while (show_menu == true);
}

void RemoveElements(Node **list)
{
    int menu_option;
    bool show_menu = true;
    string ui_word;
    do
    {
        cout << "\n---- Eliminar elementos -----\n";
        cout << "\t1 - Eliminar al principio\n";
        cout << "\t2 - Eliminar al final\n";
        cout << "\t3 - Eliminar alguna palabra\n";
        cout << "\t4 - Salir\n";
        cout << "Por favor, ingrese una opcion: ";
        cin >> menu_option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (menu_option)
        {
        case 1:
            RemoveAtStart(list);
            show_menu = true;
            break;
        case 2:
            RemoveAtEnd(list);
            show_menu = true;
            break;
        case 3:
            cout << "Ingresa la palabra: ";
            cin >> ui_word;
            RemoveWord(list, ui_word);
            ui_word = "";
            show_menu = true;
            break;
        case 4:
            show_menu = false;
            break;
        default:
            cout << "La opcion ingresada no es valida. Por favor, intentar de nuevo\n\n";
            show_menu = true;
            break;
        }
    } while (show_menu == true);
}
void ShowElements(Node **list)
{
    int menu_option;
    bool show_menu = true;
    string ui_word;
    do
    {
        cout << "\n---- Mostrar elementos -----\n";
        cout << "\t1 - Mostrar todos los registros\n";
        cout << "\t2 - Mostrar el registro de alguna palabra\n";
        cout << "\t3 - Salir\n";
        cout << "Por favor, ingrese una opcion: ";
        cin >> menu_option;
        switch (menu_option)
        {
        case 1:
            PrintList(list);
            show_menu = true;
            break;
        case 2:
            cout << "Ingresa la palabra: ";
            cin >> ui_word;
            PrintWord(ui_word, list);
            ui_word = "";
            show_menu = true;
            break;
        case 3:
            show_menu = false;
            break;
        default:
            cout << "La opcion ingresada no es valida. Por favor, intentar de nuevo\n\n";
            show_menu = true;
            break;
        }
    } while (show_menu == true);
}

bool Exit(Node **list)
{
    int menu_option;
    bool show_menu = true;

    do
    {
        cout << "\n*******  PRECAUCION! AUN HAY INFORMACION SIN GUARDAR!  *******\n\n";
        cout << "\t1 - Guardar y salir\n";
        cout << "\t2 - Salir sin guardar\n";
        cout << "\t3 - Cancelar\n";
        cout << "Por favor, ingrese una opcion: ";
        cin >> menu_option;
        switch (menu_option)
        {
        case 2:
            show_menu = false;
            return false;
        case 1:
            show_menu = false;
            SaveToFiles(list);
            return false;
        case 3:
            show_menu = false;
            break;
        default:
            cout << "La opcion ingresada no es valida. Por favor, intentar de nuevo\n\n";
            show_menu = true;
            break;
        }
    } while (show_menu == true);
}
void Welcome()
{

    cout << "\n      ########  ####  ######   ######  ####  #######  ##    ##    ###    ########  ####  ####### \n";
    cout << "      ##     ##  ##  ##    ## ##    ##  ##  ##     ## ###   ##   ## ##   ##     ##  ##  ##     ##\n";
    cout << "      ##     ##  ##  ##       ##        ##  ##     ## ####  ##  ##   ##  ##     ##  ##  ##     ##\n";
    cout << "      ##     ##  ##  ##       ##        ##  ##     ## ## ## ## ##     ## ########   ##  ##     ##\n";
    cout << "      ##     ##  ##  ##       ##        ##  ##     ## ##  #### ######### ##   ##    ##  ##     ##\n";
    cout << "      ##     ##  ##  ##    ## ##    ##  ##  ##     ## ##   ### ##     ## ##    ##   ##  ##     ##\n";
    cout << "      ########  ####  ######   ######  ####  #######  ##    ## ##     ## ##     ## ####  ####### \n\n";
}
