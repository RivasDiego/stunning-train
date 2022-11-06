#include <iostream>
#include "structs.hpp"

using namespace std;

// Tree functions

Node* new_node(Street data);
void add_node(Street data, Node **tree);
void print_tree(Node *root, int counter);
void print_tree(Node *root);
Node *search_node(int ID, Node *tree);
Node *search_parent_node_helper(int ID, Node *current_node, Node *parent);
Node *search_parent_node(int ID, Node *tree);
Node *search_min_node(Node *tree);

// Street functions

Street new_street();
void print_street(Street data);
void print_street(int ID, Node *tree);

// List functions

// House functions

// File functions