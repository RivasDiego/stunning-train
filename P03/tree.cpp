#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
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

TreeNode* new_node(Street data) {
    TreeNode* p__tree_node = new TreeNode;
    p__tree_node->element = data;
    p__tree_node->left_child = NULL;
    p__tree_node->right_child = NULL;

    return p__tree_node;
}

void add_node(Street data, TreeNode **tree) {
    TreeNode* p__node = new_node(data);
    
    if ((*tree) == NULL){
        *tree = p__node;
    }else{
        int id_in_tree = (*tree)->element.ID;

        if (p__node->element.ID < id_in_tree)
            add_node(data, &(*tree)->left_child);
        else
            add_node(data, &(*tree)->right_child);
    }
    return;
}

TreeNode search_node_by_id(int ID, TreeNode **tree) {}

TreeNode search_node_by_name(string street_name, TreeNode **tree) {}

void delete_node_by_id(int ID, TreeNode **tree) {}

void delete_node_by_name(string street_name, TreeNode **tree) {}


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
void print_street(int ID, TreeNode **tree) {}

void print_tree(TreeNode *root, int counter){
    if (root == NULL)
        return;
    else{
        print_tree(root->right_child, counter+1);
        for (int i = 0; i < counter; i++)
            cout << "    ";
        cout << root->element.name << " " << root->element.ID <<   "\n";
        print_tree(root->left_child, counter+1);
    }
}

void print_tree(TreeNode *root){
    int counter = 0;
    print_tree(root, counter);
    cout << "\n";
    return;
}
