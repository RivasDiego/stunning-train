#include <iostream>
#include <iostream>
#include <algorithm>
#include <typeinfo>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "lib/functions.hpp"

using namespace std;

void show_tree(Node *tree);
void _delete_node(Node **tree);
void house_menu();
void print_banner();

int main()
{

    int menu_option = 0;
    bool show_menu = true;
    Node *RootNode = NULL;
    print_banner();

    add_node({8, "A", true}, &RootNode);
    add_node({4, "B", true}, &RootNode);
    add_node({12, "C", true}, &RootNode);
    add_node({2, "D", true}, &RootNode);
    add_node({6, "E", false}, &RootNode);
    add_node({10, "F", true}, &RootNode);
    add_node({14, "G", true}, &RootNode);
    add_node({1, "H", true}, &RootNode);
    add_node({3, "I", true}, &RootNode);
    add_node({5, "J", false}, &RootNode);
    add_node({7, "K", true}, &RootNode);
    add_node({9, "L", true}, &RootNode);
    add_node({11, "M", true}, &RootNode);
    add_node({13, "N", true}, &RootNode);
    add_node({15, "O", true}, &RootNode);

    do
    {
        cout << "\nMENU PRINCIPAL\n";
        cout << "\t1 - Agregar registros\n";
        cout << "\t2 - Eliminar registros\n";
        cout << "\t3 - Mostrar registros actuales\n";
        cout << "\t4 - Menu de casas\n";
        cout << "\t5 - Salir\n";
        cout << "\nPor favor, ingrese una opcion: ";
        cin >> menu_option;
        switch (menu_option)
        {
        case 1:
            add_node(new_street(), &RootNode);
            show_menu = true;
            break;
        case 2:
            _delete_node(&RootNode);
            show_menu = true;
            break;
        case 3:
            show_tree(RootNode);
            show_menu = true;
            break;
        case 4:
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
    } while (show_menu);

    return 0;
}

void show_tree(Node *tree)
{
    int menu_option;
    bool show_menu = true;
    int ui_street_id;
    do
    {
        cout << "\n---- Mostrar registros -----\n";
        cout << "\t1 - Mostrar todos los registros en forma de arbol\n";
        cout << "\t2 - Mostrar todos los registros en In-Orden\n";
        cout << "\t3 - Mostrar todos los registros en Pre-Orden\n";
        cout << "\t4 - Mostrar todos los registros en Post-Orden\n";
        cout << "\t5 - Mostrar el registro de algun ID de calle\n";
        cout << "\t6 - Salir\n";
        cout << "Por favor, ingrese una opcion: ";
        cin >> menu_option;
        switch (menu_option)
        {
        case 1:
            print_tree(tree);
            show_menu = true;
            break;
        case 2:
            inorder_traversal(tree);
            show_menu = true;
            break;
        case 3:
            preorder_traversal(tree);
            show_menu = true;
            break;
        case 4:
            postorder_traversal(tree);
            show_menu = true;
            break;
        case 5:
            cout << "Ingrese el ID de la calle a imprimir: ";
            cin >> ui_street_id;
            print_street(ui_street_id, tree);
            ui_street_id = 0;
            show_menu = true;
            break;
        case 6:
            show_menu = false;
            break;
        default:
            cout << "La opcion ingresada no es valida. Por favor, intentar de nuevo\n\n";
            show_menu = true;
            break;
        }
    } while (show_menu);
}

void _delete_node(Node **tree)
{
    int ui_street_id;
    cout << "Ingrese el ID de la calle a eliminar: ";
    cin >> ui_street_id;
    Node *node_to_delete = search_node(ui_street_id, (*tree));
    Node *parent_node_to_delete = search_parent_node(ui_street_id, (*tree));
    if (node_to_delete->element.name == "INVALID_DATA")
    {
        cout << "\n\t\t***ERROR***\nNo se puede eliminar el registro...\n";
        return;
    }
    else
        delete_node(&node_to_delete, &parent_node_to_delete);
}
void house_menu();

void print_banner()
{
    cout << "\n   ###    ########  ########   #######  ##          ########  ######## \n";
    cout << "  ## ##   ##     ## ##     ## ##     ## ##          ##     ## ##       \n";
    cout << " ##   ##  ##     ## ##     ## ##     ## ##          ##     ## ##       \n";
    cout << "##     ## ########  ########  ##     ## ##          ##     ## ######   \n";
    cout << "######### ##   ##   ##     ## ##     ## ##          ##     ## ##       \n";
    cout << "##     ## ##    ##  ##     ## ##     ## ##          ##     ## ##       \n";
    cout << "##     ## ##     ## ########   #######  ########    ########  ######## \n\n";
    cout << " ######     ###    ##       ##       ########  ######                  \n";
    cout << "##    ##   ## ##   ##       ##       ##       ##    ##                 \n";
    cout << "##        ##   ##  ##       ##       ##       ##                       \n";
    cout << "##       ##     ## ##       ##       ######    ######                  \n";
    cout << "##       ######### ##       ##       ##             ##                 \n";
    cout << "##    ## ##     ## ##       ##       ##       ##    ##                 \n";
    cout << " ######  ##     ## ######## ######## ########  ######                  \n";
}
