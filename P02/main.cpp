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
        cout << "\t1 - Agregar registros\n";
        cout << "\t2 - Eliminar registros\n";
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
    string ui_phone_number;
    do
    {
        cout << "\n---- Agregar registros -----\n";
        cout << "\t1 - Agregar registro al principio\n";
        cout << "\t2 - Agregar registro al final\n";
        cout << "\t3 - Agregar registro antes de algun numero de contacto\n";
        cout << "\t4 - Agregar registro despues de algun numero de contacto\n";
        cout << "\t5 - Salir\n";
        cout << "Por favor, ingrese una opcion: ";
        cin >> menu_option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (menu_option)
        {
        case 1:
            AddAtStart(CreateContact(), list);
            show_menu = true;
            break;
        case 2:
            AddAtEnd(CreateContact(), list);
            show_menu = true;
            cout << "La operacion se ejecuto exitosamente\n";
            break;
        case 3:
            cout << "Ingresa el numero de contacto a buscar: ";
            cin >> ui_phone_number;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            AddBefore(CreateContact(), list, ui_phone_number);
            ui_phone_number = "";
            show_menu = true;
            break;
        case 4:
            cout << "Ingresa el numero de contacto a buscar: ";
            cin >> ui_phone_number;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            AddAfter(CreateContact(), list, ui_phone_number);
            ui_phone_number = "";
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
    string ui_phone_number;
    do
    {
        cout << "\n---- Eliminar registros -----\n";
        cout << "\t1 - Eliminar registro al principio\n";
        cout << "\t2 - Eliminar registro al final\n";
        cout << "\t3 - Eliminar registro de algun numero de contacto\n";
        cout << "\t4 - Eliminar todos los registros\n";
        cout << "\t5 - Salir\n";
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
            cout << "Ingresa el numero de contacto a buscar: ";
            cin >> ui_phone_number;
            RemoveContact(list, ui_phone_number);
            ui_phone_number = "";
            show_menu = true;
            break;
        case 4:
            RemoveAll(list);
            show_menu = false;
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
void ShowElements(Node **list)
{
    int menu_option;
    bool show_menu = true;
    string ui_phone_number;
    do
    {
        cout << "\n---- Mostrar registros -----\n";
        cout << "\t1 - Mostrar todos los registros\n";
        cout << "\t2 - Mostrar el registro de algun numero de contacto\n";
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
            cout << "Ingresa el numero de contacto a buscar: ";
            cin >> ui_phone_number;
            PrintContact(ui_phone_number, list);
            ui_phone_number = "";
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
        cout << "\n*******  PRECAUCION! PUEDE QUE EXISTA INFORMACION SIN GUARDAR!  *******\n\n";
        cout << "\t1 - Guardar y salir\n";
        cout << "\t2 - Salir sin guardar\n";
        cout << "\t3 - Cancelar\n";
        cout << "Por favor, ingrese una opcion: ";
        cin >> menu_option;
        switch (menu_option)
        {
        case 1:
            SaveToFiles(list);
            show_menu = false;
            return false;
        case 2:
            show_menu = false;
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
cout << "\n██╗     ██╗██████╗ ██████╗  ██████╗     ██████╗ ███████╗                      \n";
cout << "██║     ██║██╔══██╗██╔══██╗██╔═══██╗    ██╔══██╗██╔════╝                      \n";
cout << "██║     ██║██████╔╝██████╔╝██║   ██║    ██║  ██║█████╗                        \n";
cout << "██║     ██║██╔══██╗██╔══██╗██║   ██║    ██║  ██║██╔══╝                        \n";
cout << "███████╗██║██████╔╝██║  ██║╚██████╔╝    ██████╔╝███████╗                      \n";
cout << "╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝ ╚═════╝     ╚═════╝ ╚══════╝                      \n";
cout << "                                                                              \n";
cout << " ██████╗ ██████╗ ███╗   ██╗████████╗ █████╗  ██████╗████████╗ ██████╗ ███████╗\n";
cout << "██╔════╝██╔═══██╗████╗  ██║╚══██╔══╝██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██╔════╝\n";
cout << "██║     ██║   ██║██╔██╗ ██║   ██║   ███████║██║        ██║   ██║   ██║███████╗\n";
cout << "██║     ██║   ██║██║╚██╗██║   ██║   ██╔══██║██║        ██║   ██║   ██║╚════██║\n";
cout << "╚██████╗╚██████╔╝██║ ╚████║   ██║   ██║  ██║╚██████╗   ██║   ╚██████╔╝███████║\n";
cout << " ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝\n";
                                                                              
}
