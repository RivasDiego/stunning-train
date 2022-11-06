#include <iostream>
#include <string>
#include "lib/functions.hpp"

using namespace std;

Node* new_node(Street data) {
    Node* p__tree_node = new Node;
    p__tree_node->element = data;
    p__tree_node->left_child = NULL;
    p__tree_node->right_child = NULL;

    return p__tree_node;
}

void add_node(Street data, Node **tree) {
    Node* p__node = new_node(data);

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

void print_tree(Node *root, int counter){
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

void print_tree(Node *root){
    int counter = 0;
    cout << "\n";
    print_tree(root, counter);
    cout << "\n";
    return;
}

Node *search_node(int ID, Node *tree)
{
    if (!(tree == NULL))
    {
        if (tree->element.ID == ID)
            return tree;
        if (ID < tree->element.ID)
            return search_node(ID, tree->left_child);
        return search_node(ID, tree->right_child);
    }
    return new_node(INVALID_STREET);
}

Node *search_parent_node_helper(int ID, Node *current_node, Node *parent)
{
    if (!(current_node == NULL))
    {
        if (current_node->element.ID == ID)
            return parent;
        if (ID < current_node->element.ID)
            return search_parent_node_helper(ID, current_node->left_child, current_node);
        return search_parent_node_helper(ID, current_node->right_child, current_node);
    }
    return new_node(INVALID_STREET);
}

Node *search_parent_node(int ID, Node *tree)
{
    return search_parent_node_helper(ID, tree, NULL);
}

Node *search_min_node(Node *tree)
{
    if (!(tree == NULL))
    {
        if (tree->left_child)
            return search_min_node(tree->left_child);
        return tree;
    }
    return NULL;
}