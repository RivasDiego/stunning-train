#include <iostream>
#include <string>
#include "lib/functions.hpp"

using namespace std;

Node *new_node(Street data){
    Node *p__tree_node = new Node;
    p__tree_node->element = data;
    p__tree_node->left_child = NULL;
    p__tree_node->right_child = NULL;

    return p__tree_node;
}

void add_node(Street data, Node **tree){
    Node *p__node = new_node(data);

    if ((*tree) == NULL)
    {
        *tree = p__node;
        return;
    }
    
    int id_in_tree = (*tree)->element.ID;
    if (p__node->element.ID < id_in_tree)
        add_node(data, &(*tree)->left_child);
    else
        add_node(data, &(*tree)->right_child);
    return;
}

void print_tree(Node *root, int counter){
    if (is_tree_empty(root))
        return;
    else
    {
        print_tree(root->right_child, counter + 1);
        for (int i = 0; i < counter; i++)
            cout << "    ";
        cout << root->element.name << " " << root->element.ID << "\n";
        print_tree(root->left_child, counter + 1);
    }
}

void print_tree(Node *root){
    if (is_tree_empty(root)){
        cout << "El arbol esta vacio...";
        return;
    }
    int counter = 0;
    cout << "\n";
    print_tree(root, counter);
    cout << "\n";
    return;
}

Node *search_node(int ID, Node *tree){
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

Node *search_parent_node_helper(int ID, Node *current_node, Node *parent){
    if (!(current_node == NULL))
    {
        if (current_node->element.ID == ID)
            return parent;
        if (ID < current_node->element.ID)
            return search_parent_node_helper(ID, current_node->left_child, current_node);
        return search_parent_node_helper(ID, current_node->right_child, current_node);
    }
    return NULL;
}

Node *search_parent_node(int ID, Node *tree){
    Node *p__node = new Node;
    Node *temp_node = search_node(ID, tree);

    p__node = search_parent_node_helper(ID, tree, NULL);
    if (p__node == NULL && temp_node->element.ID == -1)
        return new_node(INVALID_STREET);
    if (p__node == NULL)
    {
        return tree;
    }
    return p__node;
}

Node *search_min_node(Node *tree){
    if (!(tree == NULL))
    {
        if (tree->left_child)
            return search_min_node(tree->left_child);
        return tree;
    }
    return NULL;
}

void swap_nodes(Node** old_node, Node** new_node){
    Node* temp_node = *old_node;
    (*old_node)->element = (*new_node)->element;
}

void delete_node(Node **node_to_delete, Node **parent_of_node_to_delete){
    if (is_leaf(*node_to_delete))
    {
        if ((*parent_of_node_to_delete)->left_child == *node_to_delete)
        {
            delete (*node_to_delete);
            (*parent_of_node_to_delete)->left_child = NULL;
            return;
        }
        delete (*node_to_delete);
        (*parent_of_node_to_delete)->right_child = NULL;
        return;
    }
    if (has_both(*node_to_delete)){
        Node* min = search_min_node((*node_to_delete)->right_child);
        Node* min_parent = search_parent_node(min->element.ID, (*node_to_delete));
        (*node_to_delete)->element = min->element;
        delete_node(&min, &min_parent);
    }
    if (has_only_left(*node_to_delete)){
        swap_nodes(node_to_delete, &(*node_to_delete)->left_child);
        delete_node(&(*node_to_delete)->left_child,node_to_delete);
    }
    if (has_only_right(*node_to_delete)){
        swap_nodes(node_to_delete, &(*node_to_delete)->right_child);
        delete_node(&(*node_to_delete)->right_child,node_to_delete);
    }
}

bool is_leaf(Node *node){
    return node->left_child == NULL && node->right_child == NULL;
}
bool has_only_left(Node *node) {
    return node->left_child != NULL && node->right_child == NULL;
}
bool has_only_right(Node *node) {
    return node->left_child == NULL && node->right_child != NULL;
}
bool has_both(Node *node) {
    return node->left_child != NULL && node->right_child != NULL;
}
bool is_root(Node *node, Node *parent) {
    return node == parent;
}

bool is_tree_empty(Node *root)
{
    return root == NULL;
}
void inorder_traversal(Node* tree){
    if (is_tree_empty(tree)){
        cout << "El arbol esta vacio...";
        return;
    }
    inorder_traversal(tree->left_child);
    cout << tree->element.ID << ", ";
    inorder_traversal(tree->right_child);
}
void preorder_traversal(Node* tree){
    if (is_tree_empty(tree)){
        cout << "El arbol esta vacio...";
        return;
    }
    cout << tree->element.ID << ", ";
    preorder_traversal(tree->left_child);
    preorder_traversal(tree->right_child);
}
void postorder_traversal(Node* tree){
    if (is_tree_empty(tree)){
        cout << "El arbol esta vacio...";
        return;
    }
    postorder_traversal(tree->left_child);
    postorder_traversal(tree->right_child);
    cout << tree->element.ID << ", ";
}