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
void swap_nodes(Node** old_node, Node** new_node);
void delete_node(Node** node_to_delete, Node** parent_of_node_to_delete);
bool is_leaf(Node* node);
bool has_only_left(Node* node);
bool has_only_right(Node* node);
bool has_both(Node* node);
bool is_root(Node* node, Node* parent);

// Street functions

Street new_street();
void print_street(Street data);
void print_street(int ID, Node *tree);

// List functions

// House functions

// File functions